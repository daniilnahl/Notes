# Primitive Data Types

| Type        | Meaning                        | Minimum Size (Number of bits)         |
|-------------|--------------------------------|--------------------------------------|
| `bool`      | Boolean                        | N/A                                  |
| `char`      | Character                     | 8 bits                              |
| `wchar_t`   | Wide character                | 16 bits                             |
| `char16_t`  | Unicode character             | 16 bits                             |
| `char32_t`  | Unicode character             | 32 bits                             |
| `short`     | Short integer                 | 16 bits                             |
| `int`       | Integer                      | 16 bits (minimum is max of `short`) |
| `long`      | Long integer                 | 32 bits (minimum is max of `int`)    |
| `long long` | Long long integer            | 64 bits (minimum is max of `long`)   |
| `float`     | Single-precision floating-point | 6 significant digits               |
| `double`    | Double-precision floating-point | 10 significant digits              |
| `long double` | Extended-precision floating-point | 10 significant digits            |

---

### Side Notes  
- `extern` before a variable allows the variable to be used in other files, similar to `public` in Java.

---

### Hierarchy of Data Types
bottom to top:
int -> unsigned int -> long int -> unsigned long int -> long long int -> unsigned long long int -> float -> double -> long double. 


### Important  
**Never mix signed and unsigned types.**  
1. A signed type represents negative or positive numbers (including zero).  
2. An unsigned type represents only values greater than or equal to zero.
