# What is considered good design?
1. Separating class declration (file.h), member functions definitions (file.cpp) and the program (main.cpp) that uses the class into different files.
    - Class declaration -> class specification file -> class.h
    - function definitions -> class implementation file -> class.cpp

## Header file
- Use guards to prevent a header file from being included twice:
```
#ifndef IF_NOT_DEFINED
#define DEFINE_FILE
...(content)
#endif
```
- The names in #ifndef and #define musts always be capitalized.

# What is OOP analysis and design?
Program functionality must be determined from the requirements. These must be identified:
### identification of classes and objects
Consider main data elements and the operations on these elements. These elements are:
- User interface components.
- I/O devices.
- data.
- phyiscal objects.    
### defs of each class's attributes
Data elements of an object of an class. They are necessary for the object/class to work in the program.
### defs of each class's behaviors
Identify what an object of a class should do in the program. Its purpose.
### defs of relationships between classes
Think about the possible relationships between classes:
- Access ("uses-a")
- Ownership/composition ("has-a")
- Inheritance ("is-a")
