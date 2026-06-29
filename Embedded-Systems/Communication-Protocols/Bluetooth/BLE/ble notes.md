# What is BLE?
BLE is a *version* of bluetooth thats specifically designed for **low power consumption** IoT devices like smart watches, fitness trackers and radio beacons.

**Important difference between BLE and Classical Bluetooth is that unlike classical bluetooth which is always connected, BLE is usually idle (standby mode) and wakes up only if required.**

## What are states of BLE?
- Standby - idle, not sending or receiving.
- Advertising - device is broadcsating data packets to announce its presence and capabilities.
- Scanning - listening for advertisements from other devices to discover them. 
- Initiating - device has found a target via scanning and is actively sending a connection request.
- Connected -  two devices have established a link, can exchange data, and maintain the connection until one side terminates.

## What are the layers in BLE?
Here are shown the layers with what those layers hold.
- **Application**: the “top” layer that directly serves the end user or device’s main function.
    - User interface, data handling and logic.
- **Host** handles high level stuff: organizing data, managing who you’re talking to, securing the connection, and following agreed-upon formats so devices understand each other.
    - HCI – Host side Host-Controller Interface
    - L2CAP – Logical Link Control and Application Protocol
    - SM – Security Manager
    - ATT – Attribute Protocol
    - GAP – Generic Access Profile
    - GATT – Generic Attribute Profile - defines the specifications for data transfer between BLE devices using *Service* and *Characteristics*.
- **Controller** handles low level stuff: controls the actual Bluetooth radio: turning it on/off, sending/receiving signals, keeping track of when to talk or listen, and following the basic Bluetooth rules so devices can communicate without interfering.
    - PHY – The Physical Layer
    - LL – The Link Layer
    - HCI – Controller side Host-Controller Interface


# Why does BLE exist?
It exists as an alternative for classical bluetooth for devices that have limited power resources,

# How does it work?
It can work in two ways: **Broadcast** or **Connection**. 
- in **Broadcast**, broadcaster (BLE device) sends to an oberserver (a different BLE device). Its a one way transfer.
- in **Connection**, Master (central BLE device) continuously scans for advertising data packets from Slaves (peripheral BLE devices) which send the packets.

 #VOCAB
- **Characteristic:** Characteristic is a group of information called Attribute and Attribute is a group of information transferred between devices. A characteristic usually contains the following attributes:
    - Value: Data value of the characteristic
    - Declaration: Properties of the characteristic (location, type like read, write, notify, indicate etc.)
    - Description: ASCII String describing the characteristic.
    - Service: A collection of characteristics is called a Service. Each Service has a unique 16-bit or 128-bit ID called UUID.
    - UUID: Universally Unique Identifier is a 128-bit ID given to each service and characteristic in a profile. Use the website UUIDGenerator to generate unique IDs. Each service and characteristic has a unique 16-bit or 128-bit ID called UUID. A sample UUID looks something like this: 583f8b30-74b4-4757-8143-56048fd88b25
- **Advertising data packets**: small periodically transmitted messages sent by a device to announce its presence and capabilities. Such packets data usually holds the device's  name, services offered, and other relevant data.