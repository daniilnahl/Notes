# Constants
They are types of variables that can't be modified after initialization. 
## How to tell if a var is a constant?
### Integer 
- decimal - between 0 to 9 digits, cant begin with 0 - 15, 255.
- octal - between 0 and 7 digits, must begin with 0 - 017, 0377.
- hexadecimal - between 0 and 9 digits and letters between a and f, ALWAYS begin with 0x.
 - binary - 0s an 1s, must begin with 0b. 0b011.

### Floating
By default float constants are stored as double precision numbers.BUT HERE HOW TO CHANGE THAT:
- 57.0F/f - single precision
- 57.0L/l - double precision

## How to make constants?
- To force compiler to treat a constant as a long integer, follow the value with L.
- *Note*: to indicate a constant is unsigned, follow the value with U.

# Simple Overlows
## Integer overflow
**TWO MAIN BEHAVIORS**:
- SIGNED INTEGER - behavior is undefined.
- UNSIGNED INTEGER - result is defined, but the answer is (correct answer) %(module) 2 ^ n, n is num of bits used to store the result.

# Chars Expanded
Each char has an ASCII value which is a short int type and **char CONSTANTS have int type.**
## What does this mean?
It means you can add, subtract and compare integer values. 
```
ADDING/SUBTRACTING
char ch;
ch = 65  //ch is 'A'
ch = ch + 1 //ch is 'B'
```
## How to read and write chars?
Char is a unique type and for this unique type there is a unique way to read and write them. Introducing:
- puthchar('q'); -> writes a single char.
- var = getchar(); -> reads a single char. (returns int type).

# Bools Expanded
Bool, you know what it is. To use it in C do this:
- #include <stdbool.h>

# Casting Expanded

# Type Definitions

# Escape Sequences
- Alert (bell) \a
- Backspace \b
- Form feed \f
- New line \n
- Carriage return \r
- Horizontal tab \t
- Vertical tab \v