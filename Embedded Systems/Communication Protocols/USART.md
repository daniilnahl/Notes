# What is USART?
A serial communication protocol that can operate in both **synchronous** and **asynchronous** modes. 

### Key Characteristics
- **Serial**: data is transmitted one bit at a time. Baud rate != Bit rate. Baud rate is a measure of symbols per second while bit rate is number of bits per second. Thus Baud rate == Bit rate iff each symbol represents one bit.
- **Asynchronous**
    - **No shared clock** signal between sender and receiver.
    - Synchronization relies on agreed-upon parameters like **baud rate**, data bits, parity, and stop bits.
    - Start and stop bits frame each byte of data.

- **Synchronous**
    - A **shared clock signal** (typically provided by the master) synchronizes data transfer.
    - Used for higher data rates or when a clock line is available.
    - Less common usage because synchronous is easier and has solid data rates.

### Pros
- Simple to set-up: once the baud rates are matched, data can be sent and received.
- Data can be sent and received simultaneously using separate transmit (TX) and receive (RX) lines.
- Easy to debug due to easy connection set-up to PCs.
- RTS/CTS lines prevent buffer overflows = reliable data transfer over longer distances or varying data rates.
- **No addressing**. In a typical point-to-point setup, no addressing scheme needed.

### Cons
- Each device requires its own TX and RX lines to the microcontroller.
- No "built-in" Multi-Master/Multi-Slave.
- **MUST BE EXTREMELY** careful with setting correct baud rate.


#### Ideal Usage
- Debugging and Logging: Sending debug messages to a computer terminal is one of the most common uses of UART.
-Communication with GPS Modules, Bluetooth Modules, Wi-Fi Modules: Many wireless communication modules and GPS receivers expose a UART interface.
- Interfacing with Modems: Traditional modems use UART for communication.
- Simple Point-to-Point Device Communication: When two devices need to exchange data reliably over a dedicated connection, such as a microcontroller talking to a specific sensor that uses UART.
- Firmware Updates: Many microcontrollers allow for firmware updates over a UART interface.
- RS-232/RS-485 Communication: UART forms the basis for these industrial serial communication standards, allowing for longer distances and multi-drop networks with appropriate transceivers.
