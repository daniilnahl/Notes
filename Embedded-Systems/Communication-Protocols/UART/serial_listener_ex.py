#Example of how to listen to serial wire through pc using python
#1. create virtual environment: python -m venv "name"
#2. activate it
#3. install pyserial: pip install pyserial
#4. run code

#python -m serial.tools.list_ports  --- shows the serial ports
import serial

ser = serial.Serial(port='[PORT NAME]',baudrate=115200)

while True:
    value_raw = ser.readline()
    value_string = str(value_raw, 'UTF-8')
    print(value_string)
    
    
    
    
#Thanks to Avirup Basu for the awesome tutorial