






Read through and read through again and write down notes.








## Chapter 2: register manipulation to blink an led
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
**ODR:** output data register.


The 'U' and 'UL' both indicate that the number will be unsigned, but 'L' signifies a long integer.
```
define NUMBER        (100U)
define BIGGER_NUMBER (1000UL)
```
### Init Examples
assembly
```
EQU GPIOE_MODER, [ADDRESS]
EQU RCC_AHB1ENR, [ADDRESS]
//ENABLE CLOCK
LDR R0, = RCC_AHB4ENR
LDR R1, [R0]
ORR R1, R1, #(1 << 0)
STR R1, [R0]

// SET E3 AS OUTPUT PIN
LDR R0, =GPIOE_MODER
LDR R1, [R0]
ORR R1, R1, #(1 << 10)
STR R1, [R0]
```

C
```
//these two lines define pointers to specific registers within memory 
// (BASE + OFFSET)
#define GPIOE_MODER (*(volatile unsigned long *) (GPIOE_BASE + 0x00)) //points to GPIO port E mode register 
#define RCC_AHB4ENR (*(volatile unsigned long *) (RCC_BASE + 0x0E0))  //points to RCC AHB4 peripheral clock enable register.
// the volatile keywords tell the compiler that these macros are treated as memory mapped registers

//enable clock for GPIOE by setting the 0 bit (frist bit). '|=' makes sure that only the specified bit is modified 
RCC_AHB4NER |= (1 << 0); 

//set E3 to output mode
GPIOE_MODER |= (1 << 10); //setting bit 10 MODER3[1] 
```

Low level driver
```
//libraries to handle the 
#include "stm32h7xx_ll_bus.h"
#include "stm32h7xx_ll_gpio.h"
//enabling gpio clock for specific pin group
LL_AHB4_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOE);
//configuring the pin 
LL_GPIO_SetPinMode(GPIOE, LL_GPIO_PIN_3, LL_GPIO_MODE_OUTPUT);
```

Hardware abstraction layer
```
#include "stm32h7xx_hal.h"
	GPIO_InitTypeDef GPIO_InitStruct = {0}; //GPIO pin structure which is used to configure GPIO pin properties
	//enable the gpio clock which ensures GPIO peripheral is powered and can function
	__HAL_RCC_GPIOE_CLK_ENABLE();

	//configuring the pin
	GPIO_InitStruct.Pin = GPIO_PIN_3; //pin 3 of port PE
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP; //configure pin as output
	HAL_GPIO_Init(GPIOE, &GPIO_InitStruct); //initialize PE3 pin with the settings estabilished in the struct
```

## Chapter 3: Understanding Build Process and Exploring GNU Toolchain
### Reviewing the embedded build process
source files (.h & .c) --> **[preprocessor]** --> preprocessed files (.i) --> **[compiler]** --> assembly files (.s)--> **[assembler]** --> object files (.o) --> **[linker]** --> relocatable file --> **[locator]** --> executable 

1. **Preprocessing**: 
	- strips out comments.
	- evalautes are pre-processed directives like: #define, #include, #ifdef etc. Replaces the directives with the defined values and corresponding code segments.
2. **Compilation**:
 	- compiles C code into architecture specific assembly. 
3. **Assembly**:
	- converts assembly into machine code.
	- creates the object files, .o
4. **Linking**:
	- links all the object and C standard library files together.
	- handles dummy memory allocation for variables and functions.
	- resolves references between code modules.
	- outputs a 'relocatable file' which is a file used in 'relocation' process where dummy addresses within the relocatable files (the object files) are translated into specific memory locations. 
	- Basically at this stage links all the object files together but with dummy addresses.
5. **Location stage**:
	- Requires the previously linked object files and linker file to create the final executable.
	- 'Locator' used linker file to place code and variables from object files into designated memory sections. 
	- Outputs the '.elf' 


- **'.elf'** - executable and linkable file format. The file format that is used to run the embedded application with debug mode through STM32IDE or TI CCS. Includes a bunch of metadata that is not used in the program but is useful for debugger to walk through the app.
- **'.bin'** - raw binary of the application stripped of all metadata. The bootloader (or programming tool) must be told at what address to put this raw application, and it then loads it sequentially into that specified section of memory.

### GNU Tools
Simple breakdown of what each word means in this **'arm-none-eabi-gcc'**:
1. arm -> the architecture of target
2. none -> OS for which the code is being compiled for. (Bare-metal in this case)
3. eabi -> standard for the binary layout of the system, user programs, libraries, etc.
4. gcc -> GNU compiler collection.

##### GNU ARM Embedded Binary Tools

| Tool | Description |
| :--- | :--- |
| `arm-none-eabi-gcc` | The core C compiler driver. It coordinates the preprocessor, compiler, assembler, and linker to build your final executable. |
| `arm-none-eabi-nm` | Lists symbols (functions, variables) from object files and executables, displaying their memory addresses and section types. |
| `arm-none-eabi-size` | Prints the memory size of sections (e.g., `.text` for flash, `.data`/`.bss` for RAM) and the total size of the file. |
| `arm-none-eabi-objdump` | Displays detailed info from object files. Most commonly used to disassemble the binary back into readable assembly code. |
| `arm-none-eabi-readelf` | Parses and displays the internal structure of ELF files (headers, sections, symbol tables) without relying on debugging tools. |
| `arm-none-eabi-objcopy` | Copies and translates files between object formats (e.g., stripping metadata to convert your `.elf` into a raw `.bin`). |

##### Common Compiler Flags

| Flag | Description |
| :--- | :--- |
| `-Werror` | Treats all compiler warnings as fatal errors, forcing the build to stop until they are fixed. |
| `-Wall` | Enables a broad, standard set of compiler warnings to catch potentially problematic or unsafe code. |
| `-ansi` | Enforces strict ANSI C (C89/C90) standard compliance and disables GCC-specific compiler extensions. |
| `-mcpu=[name]` | Specifies the exact target processor (e.g., `cortex-m7`) so the compiler uses features and optimizations specific to that chip. |
| `-march=[name]` | Specifies the target instruction set architecture (e.g., `armv7e-m`) rather than a specific processor model. |
| `-mtune=[name]` | Optimizes the code's performance and scheduling for a specific CPU, without restricting the instructions to *only* that CPU. |
| `-mthumb` (or `-thumb`) | Instructs the compiler to generate the 16-bit/32-bit Thumb instruction set (which is required for Cortex-M chips like the STM32). |
| `-marm` | Instructs the compiler to generate the standard 32-bit ARM instruction set (Note: Cortex-M microcontrollers do not support this). |
| `-I [dir]` | Adds the specified directory `[dir]` to the list of paths the compiler searches when looking for `#include` header files. |

### Building an application from terminal
- **OpenOCD:** Open on chip debugger. Transferer of firmware to a microcontroller + debugger.
Below commands starts openOCD with all necessary configuration info to be able to properly communicate with my STM32H743 mcu. 
```
openocd -f interface/stlink-v2.cfg -f target/stm32h7x.cfg
```
Note with the stm32 install on ubuntu it comes with a custom openOCD which will only work with stm32's custom scripts. The 'sudo apt install openocd' will not work with stm32's custom scripts, it must use its own!

Annotated output:
```
Info : auto-selecting first available session transport "hla_swd". To override use 'transport select <transport>'.
Info : The selected transport took over low-level target control. The results might differ compared to plain JTAG/SWD


//Below ports are used to send commands to OpenOCD and interact with OpenOCD during debug
Info : Listening on port 6666 for tcl connections		
Info : Listening on port 4444 for telnet connections


Info : clock speed 1800 kHz
Info : STLINK V2J47S7 (API v2) VID:PID 0483:3748
Info : Target voltage: 3.307847
Info : [stm32h7x.cpu0] Cortex-M7 r1p1 processor detected
Info : [stm32h7x.cpu0] target has 8 breakpoints, 4 watchpoints

//starts the gdb server and specifies which port
Info : starting gdb server for stm32h7x.cpu0 on 3333
Info : Listening on port 3333 for gdb connections
```


```
monitor flash write_image erase [application name].elf
```

- **GDB server:** this server allows the GNU Debugger to connect as a client for debugging. 

Note to self the below is the directory where the GNU toolchain lives on my pc.
```
/opt/st/stm32cubeide_2.1.1/plugins/com.st.stm32cube.ide.mcu.externaltools.gnu-tools-for-stm32.14.3.rel1.linux64_1.0.100.202602081740/tools/
```

***How to start the GNU Debugger from terminal and load firmware in?***
1. Start the 'arm-none-eabi-gdb':
```
/opt/st/stm32cubeide_2.1.1/plugins/com.st.stm32cube.ide.mcu.externaltools.gnu-tools-for-stm32.14.3.rel1.linux64_1.0.100.202602081740/tools/bin/arm-none-eabi-gdb
```  
2. connect to the gdb server port (port from the openOCD info output):
```
target remote localhost:3333
```
3. Reset and initialize the mcu
```
monitor reset init
```
4. Load the firmware and erase the previous application there
```
monitor flash write_image [application name].elf
```
5. Reset and init the mcu again
```
monitor reset init
```
6. Resume the execution
```
monitor resume
```

Also additonal note, whenever you build stuff in STM32IDE the terminal shows you what build and compile commands are run. You can always take those and manually re-do the whole process.


