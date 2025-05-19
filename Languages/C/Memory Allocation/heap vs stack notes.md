# Stack vs Heap Memory

## 1. What is it?

Stack and heap are two different ways that memory is organized and managed in a computer program.  
They serve different purposes and have distinct characteristics.

---

## 2. How does it work?

### Stack

- The stack is a region of memory managed in a **Last-In, First-Out (LIFO)** manner.
- Used for:
  - Local variables
  - Function call information (return addresses, parameters)
  - Temporary data
- When a function is called, a **stack frame** is pushed onto the stack.
- When the function returns, its stack frame is popped off.
- Allocation/deallocation is **automatic** and **fast**.
- Stack size is usually **fixed**, determined at compile time or program startup.

### Heap

- The heap is a region used for **dynamic memory allocation**.
- Allocation and deallocation are handled **explicitly** by the programmer using:
  - `malloc()`
  - `calloc()`
  - `realloc()`
  - `free()`
- Memory allocated on the heap **persists** until explicitly freed.
- The heap is generally **larger** and allows for **more flexible** memory management.

---

## 3. Why does it work?

- The **stack’s LIFO** structure matches the natural behavior of function calls and returns.
  - Automatic memory management simplifies short-lived data handling.
- The **heap** allows memory allocation when:
  - Size or lifetime is **not known** at compile time.
  - Data must persist **beyond the scope** of a function.
  - Data structures need to be **resized or dynamically managed**.

---

## 4. When does this work?

### Stack is used for:
- Local variables declared within functions.
- Function parameters passed during function calls.
- Return addresses when a function is called.
- Temporary variables used within a function.

### Heap is used for:
- Dynamically allocated data structures:
  - Linked lists
  - Trees
  - Arrays with variable size
- Objects created using `new` (C++) or similar mechanisms.
- Data that must **persist** beyond the function scope.

---

## Tips

- Be aware of **stack overflow** errors:
  - Caused by too much data on the stack (e.g., large arrays, deep recursion).
- Always `free()` heap memory after use to avoid **memory leaks**.
- Understand **scope and lifetime**:
  - Stack variables: tied to function execution.
  - Heap variables: persist until explicitly freed.
