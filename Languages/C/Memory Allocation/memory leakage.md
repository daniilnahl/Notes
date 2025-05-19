# Memory Leaks

## 1. What is it?

A **memory leak** occurs when a program allocates memory from the heap but **fails to release it** back to the system when it's no longer needed.  

Over time, this can lead to the program consuming an **excessive amount of memory**, potentially causing:

- Slowdowns  
- Crashes  
- System-wide instability  

In simple terms: memory you no longer need continues to take up space that could be used elsewhere.

---

## 2. How does it work?

When memory is allocated using `malloc()`, `calloc()`, or `realloc()`, the program receives a **pointer** to that memory block.  

As long as the pointer is valid:
- The program can access or `free()` the memory.

If all references (pointers) to that memory are **lost without freeing it**:
- The memory becomes **inaccessible**.
- The OS still considers it **in use** by the program.
- It **cannot be reclaimed or reused**, resulting in a memory leak.

---

## 3. Why does it work?

The **operating system does not automatically reclaim** heap memory when it's no longer used.  
It depends on the **program** to explicitly release it via `free()`.

If the program fails to do so:
- The OS assumes the memory is still needed.
- It won't reassign it to other processes or parts of the program.

---

## 4. When does this happen?

Memory leaks typically arise in programs that:

- Use **dynamic memory allocation** extensively.
- Run for **long periods** of time.
- Contain **loops** or **recursive calls** that continuously allocate memory.
- Omit or incorrectly place the corresponding `free()` calls.

---

## Tips

1. **Match every allocation with a deallocation**:  
   For every `malloc()`, `calloc()`, or `realloc()`, ensure there's a corresponding `free()`.

2. **Use memory debugging tools**:  
   - [`Valgrind`](https://valgrind.org/) (Linux)
   - `AddressSanitizer` (available via GCC/Clang)

   These tools help detect memory leaks during development and testing.

3. **Consider modern memory management features**:
   - Use **smart pointers** (e.g., `std::unique_ptr`, `std::shared_ptr` in C++).
   - Use **garbage collection** mechanisms if your language supports them.
   - These tools help **automate memory management** and reduce the risk of leaks.
