There are four main **levels of abstraction** in embedded softwares development:
 1. **HAL**, hardware abstraction layer, highest abstraction layer using STM32 provided library.
 2. **LL**, low layer, similiar to HAL but leaner and with more control.
 3. C - bare metal where the program code directly interacts with hardware without any abstraction.
 4. Assembly - same as C but now just assembly.


### Linus specific tips
```
lsusb
```

Type in terminal to check what connected devices are visible to the OS.
### Vocab
- **RCC**: reset and clock control
- **ER**: control register
