# `#include`, `#define`, `#ifdef`, `#ifndef`, `#else`, `#endif`

## 1. What is it?  
These are directives for the C preprocessor, a component that runs before the actual compilation of your code. They instruct the preprocessor to perform specific actions on the source code before it's passed to the compiler.

## 2. How does it work?  
1. `#include <filename>` or `#include "filename"`  
   This directive tells the preprocessor to literally include the contents of the specified file into the current source file at the location of the directive. Angle brackets `<>` are typically used for standard library headers, while double quotes `""` are usually used for user-defined header files.  
2. `#define identifier value`  
   This directive defines a macro. The preprocessor will replace every occurrence of `identifier` in the code with `value` before compilation.  
3. `#ifdef identifier`  
   Checks if the identifier has been previously defined (usually with `#define`). If it has, the code between `#ifdef` and the next matching `#else` or `#endif` is included for compilation.  
4. `#ifndef identifier`  
   Checks if the identifier has not been previously defined. If it hasn't, the code between `#ifndef` and the next matching `#else` or `#endif` is included.  
5. `#else`  
   Used in conjunction with `#ifdef` or `#ifndef`. If the condition in the preceding `#ifdef` or `#ifndef` is false, the code between `#else` and the next matching `#endif` is included.  
6. `#endif`  
   Marks the end of a block started by `#ifdef`, `#ifndef`, or `#if`.

## 3. Why does it work?  
The preprocessor allows for code organization (through `#include`), defining constants and simple replacements (through `#define`), and enabling conditional compilation to adapt code for different environments or configurations.

## 4. When does this work?  
These directives are processed before the actual compilation of the C code. The compiler only sees the modified source code after the preprocessor has done its work.

---

## Tips:  
- Use header guards (using `#ifndef`, `#define`, and `#endif`) in header files to prevent them from being included multiple times in a single compilation unit, which can lead to errors.  
- Be mindful of the scope of `#define` macros; they are typically global within the file where they are defined (and any files that include it).  
- Use `#ifdef` and `#ifndef` for conditional compilation to manage different build configurations or enable/disable features.

---

## Vocab:  
**Conditional compilation:**  
A mechanism provided by the C preprocessor that allows you to include or exclude specific sections of code from compilation based on the evaluation of certain conditions at preprocessing time.
