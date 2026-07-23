

### What are standard memory segments and where do variable types live within them?
The memory segment is split into 4 regions:
1. *.bss*           -> 
    - block started by symbol, live in RAM.
    - Contains all global or **static** variables that are uninitialized or explicitly inited to zero. 
    - C startup code zeroes this memory out before main(). 
2. *.data*          -> 
    - lives in RAM.
    - contains global & static variables initialized to non-zero values.
    - its initial values are stored in FLASH/ROM then C startup code copies these from FLASH/ROM into RAM before main().
3. *.rodata*        ->
    - read only data.
    - lives in FLASH/ROM.
    - Contains **const** data.
4. *stack/register* ->
    - Lives in RAM (or directly in CPU).
    - local, non-static variables.
Technically 5 main types to understand split between:
- global
- within a function scope
```
int a;              -> zero initialized lives in .bss
static int b;       -> zero initialized lives in .bss
int g = 10;         -> lives in .data
void function() {
    int c;              -> un-initialized lives in stack
    static int d;       -> zero-initialized lives in .bss because static
    static const int e; -> placed in flash/rom lives in .rodata
}
```

### What are the embedded variable types?
**Main integer types:**
```
//signed integers
int8_t      -> 8 bit signed, -128 to 127
int16_t     -> 16 bit signed, -32768 to 32767
int32_t     -> 32 bit signed, -2^31 to 2^31-1
int64_t     -> 64 bit signed

//unsigned integers
uint8_t      -> 8 bit unsigned, 0 to 255
uint16_t     -> 16 bit unsigned, 0 to 65535
uint32_t     -> 32 bit unsigned, 0 to 2^32 - 1
uint64_t     -> 64 bit unsigned

//AVOID THIS IN EMBEDDED!!!!
int 
long
```

**Floating point types:**
- CRITICAL NOTE WITH THESE: the chip must have a hardware floating point unit, FPU, or the compiler will link a bunch of libraries and reduce performance and balloon application size.
- EVEN with FPU double is not always supported.
```
float -> single precision, 32-bit IEEE 754 standard.
double -> double precision, 32 or 64-bit depends on platform.
```

**Char types:**
```
char    -> 8-bit BUT!!!! platform defined! ONLY USE FOR ASCII text/string.
```

**EXTRA:**
```
//HANDLED BY PREPROCESSOR
#define MAX 1024    
#define PI 3.14

//HANDLED BY COMPILER
const uint32_t TIME = 10;
const float VOL = 3.3f;

//ENUM
typedef enum {
    led_off = 0,
    led_on = 1
} led_state_t;
```

### Good Practices
1. Local variables MUST BE explicitly initialized because otherwise the variable will contain some garbage value and without checks lead to errors in the program.

## Memory Management 101
Allocation -> usage -> freed -> repeat.

**4 Main Memory Types**:
1. STACK    -> automatic allocation for local variables.
2. HEAP     -> dynamic allocation using malloc.
3. FLASH    -> read-only and const data.
4. STATIC   -> global and static variables.

**Stack vs Heap**
|Stack  | Heap |
|-------|------|
| Automatic allocation  and freeing     |  manual allocation and freeing    |
| limited size | larger amounts of memory |

**Vocab**
- memory leak: forgetting to de-allocated memory.
- double free: freeing same memory twice.
- bound check: memory access is withing allocated regions.
- dangling pointer: a pointer which holds the address of data which no longer exists.
### Code examples
Classic stack memory
```
int function(){
    int a = 10; //memory allocated here
    return a;   //memory freed here
}
```
Classic heap memory
```
void function() {
    uint8_t buffer = malloc(1024); //manually allocated 1024 bits?
    memset(buffer, 0, 1024);
    free(buffer);

    buffer = NULL; //practice to flag state of buffer 
    if (buffer == NULL) {
        //do something
    }

}
```
Stack and heap comparison






## Pointers 101

## Arrays & Strings 101

## Structs & Unions 101

## Preprocessor Directives 101 

## Common interview questions about C


