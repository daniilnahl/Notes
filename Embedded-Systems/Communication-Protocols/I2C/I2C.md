# What is I2C?
**Synchronous, multi-master, multi-slave, serial computer bus** that requires only two bidirectional open-drain lines: Serial Data Line **(SDA)** and Serial Clock Line **(SCL)**.

### Key Characteristics
- **Synchronous**: both devices share a common clock signal(SCL/serial clock line) to synchronize data transfer.
- **Multi-master**: multiple devices can act as a master, initiating data transfers. However, only one master can control the bus at a time.
- **Multi-slave**: a single master can communicate with multiple slave devices on the same bus, each identified by a unique 7-bit (or 10-bit) address.
- **Serial**: data is transmitted one bit at a time over a single data line (SDA/serial data line).
- **Open-drain**: allows multiple devices to share the same lines without shorting each other out. Pull-up resistors are required to establish the high logic level.

### Pros
- Simple Wiring (2 Wires): Requires only SDA and SCL.
- Allows for **many devices** to be connected at the same time.
- Supports **various speed modes** (Standard-mode: 100 kbit/s, Fast-mode: 400 kbit/s, Fast-mode Plus: 1 Mbit/s, High-speed mode: 3.4 Mbit/s).
- Each **slave device has a unique address**, allowing the master to select who to interact with. 
- (ACK/NACK): The slave device acknowledges each byte received, providing a basic level of error checking.

### Cons
- Lower Speed Compared to SPI.
- The master needs to handle addressing, read/write commands, and acknowledgments (adds complexity).
- Higher numbers of devices can lead bus capacitance issues: limiting speed and/or setting up pull-up resistor.
- There's no direct hardware flow control mechanism like RTS/CTS in UART.
- Debugging requires a logic analyzer or oscilloscope to debug (due to the shared lines).


### Ideal Usage
- Connecting Multiple Low-Speed Peripherals to a Microcontroller: Ideal for sensors (temperature, humidity, pressure), EEPROMs, real-time clocks (RTCs), OLED displays, and other devices that don't require very high data rates.
- Systems with Limited Available Pins: When microcontroller pins are scarce, I2C's two-wire interface is highly advantageous.
- Communication Between Multiple Microcontrollers (as Masters): In more advanced systems, I2C can facilitate communication between several microcontrollers, each acting as a master at different times.
- Adding Expansion Boards: I2C is commonly used on development boards (like Raspberry Pi, Arduino) to add various sensor modules and expansion hats.