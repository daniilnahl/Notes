### What is a RTOS?
A real-time operating system which perfoms the same resouce management tasks as an OS does, but within a strict time constraint. Basically, a strictly scheduled and reliable resource management tool to do stuff. 

*Example of usage*:
- medical devices.
- industrial automation.
- IoT stuff.

### Why is RTOS important?
- Ensure that high-priority tasks are executed within a predictable time frame.
- Allows multiple tasks to run concurrently without interfreing with each other.

### How does an RTOS work?
**Thread aka task** is a smallest unit of execution that the *RTOS scheduler* manages. Basically, a thread is a task (sequence of execution) that RTOS scheduler runs concurrently with other tasks. 

#### Thread Lifecycle
1. Ready - thread is ready to run and is just waiting for the CPU.
2. Running - CPU is executing the thread's instructions.
3. Suspended - not doing anything (inactive) until it is explicitly resumed.

#### What is Context Switching?
A process during which RTOS switches from one thread to another thread. It does it by first saving a X thread's register values into a X thread stack, then loading Y thread's stack into the registers and exucting thread Y. "Multitasking". 