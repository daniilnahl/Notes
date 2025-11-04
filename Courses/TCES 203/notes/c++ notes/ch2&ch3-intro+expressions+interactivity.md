# Data Type Conversion
## Coercion Rule
1. char, short, unsigned short -> auto promoted to int
2. lower ranked data types are auto promoted to the type of the higher ranked on when different data types.
3. when using the = operator, the type of the expression on right will be converted to the of the variable on left.** Bypassing coercion rule.**
4. If demotion is required by the = operator,
    - the stored result may be incorrect if there is not
    enough space available in the receiving variable.
    - floating-point values are truncated when assigned
    to integer variables.
5. Coercion affects the **value** used in a calculation. It does not change the type associated with a variable.

## Type Casting
```
cout << static_cast<int>(4.2);
```
Use:
- static_cast<desired data type>(value or variable);


# Overflow and Underflow
- **Overflow** occurs when assigning a value that is too large. 
- **Underflow** occurs when assigning a value that is too close to 0 to be held in a variable.

## Examples
- Assigning a short int a value of its max(32767) + 1 will cause **overflow** and the variable will become -32768.

# Stream Manipulations
- setw(x): prints a value in a field thats at least x spaces wide.
- setprecision(x): prints float value with x sig figs.
- showpoint: always prints a decimal point for floating-point values.

# Char
- cin.ignore(n,c) - skips over next char in the input buffer. n - num of chars to skip and c - stop when c is encountered.
- .assign(n, c) - assigns n amount of c char into a string.

# Math Library
Must use:
```
#include <cmath>
```
- abs - Absolute value
- sin - Sine
- cos - Cosine
- tan - Tangent
- sqrt - Square root
- log - Natural (e) log
- pow - Raise to a power

# Random Library
Must use:
```
#include <cstdlib>
```

- rand(): random int between 0 and largest int computer holds. Will yield same sequence each tims ran.
- srand(x): inits random num generator with x 'seed' ensuring for each unique value of x the program there is a random sequence of numbers.

## Tips on using random
- Use time() from #include <ctime> to ensure that different seed values are generated each that a program runs.