# Pointers (Compound Type)

## 1. What are Pointers?  
A pointer is a compound type that **“points to”** another type. Like references, pointers are used for indirect access to other objects. A pointer does **not** have to be initialized when it is defined. It uses `*` (asterisk) to declare or dereference.

**Important distinctions:**

- **Unlike a reference, a pointer is an object in its own right.**  
  Pointers can be assigned and copied; a single pointer can point to several different objects over its lifetime.  
- **A pointer holds the address of another object, NOT the object's value.**

`void*` can hold the **address** of any data pointer type. This type of pointer is usually used to deal with memory as memory rather than objects stored in the memory.

- `*pointer` points to an existing object.  
- `**pointer` points to an existing pointer (pointer to a pointer).  
- `constexpr` denotes a constant pointer.

### Dereferencing  
Dereferencing in C++ refers to accessing the value that a pointer or an iterator is pointing to. When you dereference, you retrieve the value stored at the memory location (or container position) referenced by the pointer or iterator. It temporarily converts a pointer into a reference to modify the variable it points to.

### Advice  
Always initialize all pointers. Uninitialized pointers are a common source of run-time errors.

---

## 2. How to use a pointer?

### Using a pointer inside an array  
When we add (or subtract) an integral value to (or from) a pointer, the result is a new pointer. That new pointer points to the element the given number ahead of (or behind) the original pointer.

For example, if `i` is a pointer to the first element (`[0]`), then `i++` makes it point to the next element (`[1]`).
