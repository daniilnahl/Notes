## 1. What is recursion?

Recursion is when a function calls itself. All recursive functions utilize the call stack.

When a recursive function calls itself:

* **Tracking State**: The program needs to save the current function's state (like variable values and the return address) in a stack frame so it can resume execution after the recursive call finishes.
* **Stack Frames**: A new stack frame is created for each recursive call. This frame holds specific details for that particular function instance, such as parameter values and local variables.
* **Tail Recursion**: If the recursive call is the very last operation in a function, some compilers or interpreters can optimize it (Tail Call Optimization or TCO) to avoid creating a new stack frame. This helps prevent stack overflow but is not supported in all languages or environments.

All recursive functions must have two parts:

* **Base case**: When the function does *not* call itself. This is crucial for stopping the recursion and preventing an infinite loop.
* **Recursive case**: When the function *does* call itself. This is the step that moves the function closer to the base case.

If a recursive function lacks a proper base case or the base case is never reached, the call stack will grow indefinitely, leading to a **STACK OVERFLOW** error.

## 2. What is a call stack?

The call stack is a data structure that manages function calls within a program. It operates based on the "last in, first out" (LIFO) principle, similar to a stack of plates.

When a function is called, a new frame is pushed onto the stack. When a function finishes executing, its frame is popped off the stack.

In recursive functions, each recursive call pushes a new frame onto the call stack. For example, in a `main` function that calls other functions which in turn call helper functions, `main` is at the bottom of the call stack, and subsequent function calls are placed "on top" of it.

While using the call stack for recursion can be convenient for managing function state, a deep chain of recursive calls can cause the stack to become very large, potentially leading to high memory usage or a stack overflow if it exceeds the available memory.