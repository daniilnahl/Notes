# Bootloader 101
*What is it?*
Bootloader, boot program or bootstrap loader, a software executed by a processor post-reset. Typically executed from ROM or Flash, it is reponsible for minimal hardware initializations such as clock init, memory controllers, core system services, in case of secure boot verify the loaded application.Then retrieves application from specified memory then either by itself executes specified application code or calls an SBL (secondary bootloader to do that). In case of secure boot before executing the application it first verifies it.

ROM bootloader = System Bootloader (aka the first bootloader which is within ROM provided by vendor).



# Bootloader project notes
All placed within Bank 1, Access Interface: AXI
- Bootloader place at     -> 0x0800 0000 : 0x0801 FFFF (128kb) 
- Application placed at   -> 0x0802 0000 : 0x0803 FFFF (128kb)
- Backup app placed at    -> 0x0804 0000 : 0x0805 FFFF (128kb)
- Config placed at        -> 0x0806 0000 : 0x0807 FFFF (128kb)

---

Related: [Secure Boot](../Secure-Boot/secure-boot.md)

[Subject index](../index.md) · [Home](../../README.md)
