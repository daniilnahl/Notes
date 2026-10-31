
## Boot ROM 
### What?
**_What is Boot ROM, and how does it differ from firmware stored in external flash?_**

Device Firmware / Boot ROM / RBL / ROM Bootloader is stored in ROM and is almost a full part of the SoC due to its importance. As soon as the board turns on the ROM bootloader starts running. It does this:
- initializes the SoC hardware
- loads the secondary bootloader (SBL)

**RBL** always expects the SBL to be signed by either a dummy key or in case of secure boot being enabled, key that has been programmed into device's eFuses.


### Why?
**_Why does a SoC need immutable boot code rather than executing an application directly?_**

It provides a predictable starting point to initialize essential hardware, select a boot source, and establish initial root of trust.

### How?
**_How does Boot ROM locate, load, and authenticate the next boot stage?_**

On AM64x, the ROM follows configured boot-mode settings, reads a specially formatted boot image, processes its certificate, and loads the relevant components.

### When?
**_When does Boot ROM execute, and when does it transfer control?_**

During the initial reset and boot process, before the secondary boot
loader or application begins running.


## Bootloaders 
### What?
**_What is a bootloader, and what distinguishes a primary bootloader from a secondary bootloader (SBL)?_**

- **Bootloader** is a piece of software that is responsible for initialzing hardware in a known stable state, systems within a SoC and then either loading in a SBL or program and releaseing the control to it.
- **Primary Bootloader** is the bootloader that is launched once a device is powered ON, it handles initial hardware initialization and booting of SBL (checking that SBL is signed correctly).
- **Secondary Bootloader** is the bootloader which is reponsible for booting an application that will be run on the SoC. It is also responsible for initialization and system config more complex than what RBL does.

### Why?
**_Why use multiple bootloader stages instead of one?_**

The benefit of using a multi-bootloader mechanism is that it allows to estabilish a secure root of trust within ROM while also initializing a system that has a known state before launching the actual application.
Through this separation it also allows the SBL to do complex system configuration after its booted by BOOT ROM which would be more complicated and could expose more attack surface for the device's root of trust.


More concise answer is to keep the immutable first stage small while allowing later boot stages to support complex hardware, multiple boot media, and firmware updates.

### How?
**_How does an SBL load a multicore application and prepare individual processors for execution?_**

It locates and parses an application image, loads sections into the required memory locations, configures entry points, and starts the appropriate cores.

### When?
**_When would you use SBL NULL versus SBL OSPI?_**

SBL NULL is useful for debugger-based initialization without application loading. For example you want to debug an application directly from TI CSS.
SBL OSPI is for booting application firmware stored in OSPI flash.


## Secure Boot 
### What?
**_What is secure boot, and how does it differ from ordinary booting?_**

Secure boot verifies that firmware is authorized before executing it. It also uses cryptographic authentication to verify that an image has not been tempered with after its creation. 

### Why?
**_Why is secure boot important in embedded and safety-critical systems?_**

It helps prevent executing programs that are unauthorized and creates a safety layer for detecting if an application has been tempered with after its creation.

### How?
**_How does secure boot authenticate firmware using hashing, public-key cryptography, and digital signatures?_**

**Image preparation and signing:**
1. An asymmetric key pair is generated, consisting of a private key and a public key.
2. During device provisioning, a hash of the authorized public key is programmed into the SoC's OTP/eFuses using TI's OTP Keywriter. This establishes the hardware root of trust on an HS-SE device.
3. The firmware image is hashed using SHA-512.
4. The calculated firmware hash is embedded in an X.509 certificate along with metadata such as image size, load address, boot configuration, and software revision.
5. The X.509 certificate is digitally signed using the corresponding private key.
6. The signed certificate is packaged with the firmware image to produce a bootable image.

**Verification during secure boot:**
1. The Boot ROM loads and parses the X.509 certificate associated with the boot image, extracting the public key, digital signature, and firmware metadata.
2. ROM calculates the hash of the public key extracted from the certificate and compares it against the authorized public-key hash stored in the SoC's OTP/eFuses. If they match, the public key is considered trusted.
3. ROM calculates a SHA-512 hash of the certificate's TBSCertificate portion, which contains the public key, firmware image hash, and other boot metadata. This is the data that was originally signed using the private key.
4. ROM uses the authenticated public key to verify the certificate's digital signature. For RSA PKCS#1 v1.5, the public-key verification operation recovers an encoded digest from the signature, which is checked against the expected encoding of the independently calculated TBSCertificate hash. A match confirms that the certificate's signed contents have not been modified and were signed using the corresponding private key.
5. Once the certificate is authenticated, ROM independently calculates the SHA-512 hash of the actual bootloader image and compares it against the firmware hash embedded in the authenticated certificate. A match confirms that the firmware image has not been altered.
6. ROM also enforces applicable security policies and boot-image requirements, such as relevant software revision restrictions.
7. If all required checks succeed, the authenticated boot stage is allowed to execute. If authentication fails, the untrusted image is rejected and is not executed.

**Important distinction**: These ROM verification steps apply to the initial boot image. Authentication of application firmware loaded by the SBL is performed through TI System Firmware (SYSFW), rather than by the SBL independently.

### When?
**_When should secure boot be enforced, and when would firmware authentication fail?_**

It is particularly important for field-deployed systems and security-sensitive devices. Authentication can fail after unauthorized modification, incorrect signing, key mismatch, or an invalid certificate. Image parsing and flash-read errors are separate possible failures.

## Certificate Chains 
### What?
**_What is a digital certificate, and what is a certificate chain?_**

A digital certificate is an electronically signed doc that associates a public key with some entity. It estabilished that data was signed by the holder of a specific private key.
- **X.509** format of digital certificate.
- **Certificate Chain** establishes a sequence of trust consisting of many certificates.


### Why?
**_Why use certificates rather than distribute public keys without associated metadata?_**

Certificates are useful because a public key doesn't estabilish who owns or whether it is authorized for something. Digital certificates come into play by associating the keys with some other data. 

### When?
**_When are certificate chains used in embedded systems, and when is a single trusted key sufficient?_**

in TI AM64/243x SoC the certificate chain is replaced by public-key hash provisioned into eFuses of the SoC.

## Hardware Root of Trust
### What?
**_What is a hardware root of trust (HRoT), and what hardware mechanisms can implement it?_**

A hardware root of trust is a hardware based security mechanism that estabilish the foundation of trust within some computer system. It consists of:
- immutable Boot ROM
- Protected crypto keys or key hashes
- One-Time Programmable Memory
- Crypto hardware components

It provides the secure and trusted grounding point from which all the other applications can be launched from. 


### Why?
**_Why must the initial trust anchor be protected independently of mutable firmware?_**

It is to estabilish a chain of trust that ensures that some malicious actor can't just change the ROM, crypto keys, etc to bypass the security processes. It ensures that there is always a trusted foundation to which a system can come back to if some other layer has been compromised. 


### How?
**_How does an SoC use eFuses, key hashes, and secure firmware to establish a chain of trust?_**
1. **eFuses:** in TI Am243/64x SoC platforms they are used to store a crypto hash of an authorized public key that when secure boot is enabled is utilized to authenticate SBL and application images.
2. **Key Hasehs:** are used when boot ROM starts up and extracts a public key from a certificate of the an SBL, hashes it and compares that hash to match the hash that stored in its eFuses.


### When?
**_When are hardware trust anchors provisioned, and when are they used?_**

They are provisioned before the deployment or commercialization of a product into real world. 


---

Related: [Bootloader](../Fundamentals/bootloader.md)

[Subject index](../index.md) · [Home](../../README.md)
