# Function Prototype
The compiler must know some info before a function is called:
    - name
    - return type
    - number of params
    - data type of each param

Function prototypes must be near the top of the program. A full function definition or a prototype must be created before calling a function. 
**This is a function prototype**
```
void printHeading();
```

**This is a function header**
```
void printHeading()
```

# Passing Data into Functions
## Passing by Value
- Argument is passed to a function and a copy of its value is placed in the parameter.
- Function can't access the original variable.

## Passing by Reference
- A reference to existing variable is passed to a function.
- Function can access the original variable.

# Overloading functions
Overloaded functions are two or more functions that have the same name but differerent "signatures". Basically, allows us functions to take different types or different amount of parameters but still maintain the same name and purpose.