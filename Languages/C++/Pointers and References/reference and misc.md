# Additional C++ Concepts

## 1. Difference between Reference and Pointer  
- A pointer can be reseated (point to another address), while a reference is fixed to one object.

---

## 3. What are References? (Compound Type)  
A reference defines an alternative name for an object. It refers to another type. It uses `&` with the variable name.  
- A reference is bound to the variable it is assigned to and **must be initialized** at the time it is defined.  
- A reference can reference a pointer.

---

## 5. What Are Type Aliases?  
A type alias is a name that is a synonym for another type. Type aliases simplify complicated type definitions and emphasize the purpose for which a type is used.

---

## 6. What is `cout`, `cerr`?  
- `cout` is standard output.  
- `cerr` is standard error output.

---

## 7. Headers, Files, and Classes  
- When creating a class, put the class name in the file name and create the file as a header file.  
- Use `#define`, `#ifndef`, and `#endif` **in all header files** to prevent multiple inclusions of the class.

### Preprocessors  
A program that runs before the compiler and modifies the source text of programs. The program relies on one preprocessor facility, `#include`. When the preprocessor sees a `#include`, it replaces the directive with the contents of the specified header.
