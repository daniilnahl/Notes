# What is a RTOS?
A real-time operating system which perfoms the same resouce management tasks as an OS does, but within a strict time constraint. Basically, a strictly scheduled and reliable resource management tool to do stuff. 

*Example of usage*:
- medical devices.
- industrial automation.
- IoT stuff.

## Why is RTOS important?
- Ensure that high-priority tasks are executed within a predictable time frame.
- Allows multiple tasks to run concurrently without interfreing with each other.

# How does an RTOS work?
**Thread aka task** is a smallest unit of execution that the *RTOS scheduler* manages. Basically, a thread is a task (sequence of execution) that RTOS scheduler runs concurrently with other tasks. 

### Thread Lifecycle
1. Ready - thread is ready to run and is just waiting for the CPU.
2. Running - CPU is executing the thread's instructions.
3. Suspended - not doing anything (inactive) until it is explicitly resumed.

### What is Context Switching?
A process during which RTOS switches from one thread to another thread. It does it by first saving a X thread's register values into a X thread stack, then loading Y thread's stack into the registers and exucting thread Y. "Multitasking". 

# What are some RTOS?
## 1. FreeRTOS
**Open source** real time operating system kernel with a large community base thats designed for embedded devices. Supports many microncontroller architectures: Arm Cortex-M(stm32), AVR, PIC, etc.

### **Technical Information**
- 4kb to 12kb memory required.
- minimal processing overhead (doesn't use much cpu resource).
- Uses **preemptive task scheduling** (when high priority tasks can interrupt low priorty tasks).
- Static or dynamic memory allocation.
- Built-in software timers.

### **freeRTOS Conventions**

**Data Types**
- TickType_t:
    - based on configuration settings.
    - usigned 16-bit or 32 bit.
- BaseType_t
    - based on architecture settings.
    - usigned 16-bit or 32 bit.

**Variable Types** - Variables are prefixed with their types.
- c: char.
- s: short/uint16_t
- l: long/int32t
- u: unsigned
- p: pointer
- x: for any other type.

**Functions** - are prefixed with their return type and the name of the file in which they are defined.
- Example:
    - vTaskPrioritySet().
    - 'Task' means efined in task.c.
    - 'v' means returns void.


**Macros**
- Macro in uppercase. 
- Prefix in lowercase (indicates macro definition file).
- Example: portMAX_DELAY - located in "portable.h"

