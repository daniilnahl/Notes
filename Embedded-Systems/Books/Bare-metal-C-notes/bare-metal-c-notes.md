## Chapter 1: register manipulation to blink an led
There are four main **levels of abstraction** in embedded softwares development:
 1. **HAL**, hardware abstraction layer, highest abstraction layer using STM32 provided library.
 2. **LL**, low layer, similiar to HAL but leaner and with more control.
 3. C - bare metal where the program code directly interacts with hardware without any abstraction.
 4. Assembly - same as C but now just assembly.

To access a specific register of some pin that belong to Port A find memory map for the microcontroller. Within it locate for internal peripherals. The starting address of that block is the *base address* and all the documentation for registers (of peripherals) will be *offset* from that base address.

Within that peripheral memory black its going to be split into smaller blocks. Those blocks are named after **bus system they interact with**.
The bus blocks are the further divided into memory segements and within those segments space allocated for specific GPIO ports. For example, 

**GPIO MODER <letter>**: a mode register for a specifc port of GPIO pins. Like GPIO A or B pins. Used to set the mode of a pin being used. On STM 32 these are combos to control status of a pin:
 - 00: input
 - 01: general purpose output
 - 10: alternative functions
 - 11: analog mode 
**RCC**: rest and clock control, 
**ER**: enable register, 
**RCC_AHB#ENR:** used to enable a clock for a specifc GPIO port.
**PORTS**: pins are organized into specific ports. For example if a pin belong to Port A it will be called PA#.
**APB:** advanced peripheral bus. 
**AHB:** advanced high performance bus.
**Clock gating:** turning off the clock to specific parts of the microcontroller when those parts are not in use. ----> **RCC** has a boundary address range as well (withing the AH# aka the bus boundary).
**RCC_AHB#ENR:** reset and clock control advanced high performance enable register


The 'U' and 'UL' both indicate that the number will be unsigned, but 'L' signifies a long integer.
```
define NUMBER        (100U)
define BIGGER_NUMBER (1000UL)
```