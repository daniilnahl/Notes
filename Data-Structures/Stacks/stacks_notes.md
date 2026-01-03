## 1. What is a stack?

A stack is a linear data structure that follows the Last In, First Out (LIFO) principle. The last element added to the stack is the first one to be removed, like a stack of plates.

## 2. Why does it work this way?

There are two primary operations:

* **Push** - adds an element to the top of the stack.
* **Pop** - removes the top element.

Since the stack operates in LIFO order, the most recently added element is always accessed first. This makes it ideal for scenarios where you need to reverse processes or manage function calls.

## 3. How to use it?

* View examples (In files)

## 4. When to use this?

* When you want to access elements in LIFO order.

**Example: Undo functionality in a text editor**

A text editor allows users to undo their last action. This can be implemented using a stack:

1.  Each action is pushed onto the stack.
2.  When the user presses "Undo," the last action is popped from the stack.