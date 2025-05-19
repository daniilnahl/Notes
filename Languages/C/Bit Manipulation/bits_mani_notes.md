## 1. What is it?

Bitwise operators in C allow you to perform operations directly on the individual bits of integer data types (like `int`, `char`, `unsigned int`, etc.). The common bitwise operators are:

* **`&` (Bitwise AND)**: Performs a logical AND operation on corresponding bits of two operands. The result bit is `1` only if both corresponding bits are `1`.
* **`|` (Bitwise OR)**: Performs a logical OR operation on corresponding bits. The result bit is `1` if at least one of the corresponding bits is `1`.
* **`^` (Bitwise XOR)**: Performs a logical XOR (exclusive OR) operation. The result bit is `1` if the corresponding bits are different (one is `0` and the other is `1`).
* **`~` (Bitwise NOT)**: Performs a logical NOT (complement) operation on each bit of a single operand. It inverts the bits (`0` becomes `1`, and `1` becomes `0`). This is a unary operator.
* **`<<` (Left Shift)**: Shifts the bits of the left operand to the left by the number of positions specified by the right operand. Zero bits are shifted in from the right. Equivalent to multiplying by a power of 2.
* **`>>` (Right Shift)**: Shifts the bits of the left operand to the right by the number of positions specified by the right operand. The behavior of the bits shifted in from the left depends on whether the operand is signed (arithmetic shift, sign bit is replicated) or unsigned (logical shift, zero bits are shifted in). Equivalent to dividing by a power of 2.

## 2. How does it work?

These operators work directly at the binary level of data representation. For example, if you have two 8-bit integers, the bitwise AND operator will compare the first bit of the first integer with the first bit of the second integer, the second bit with the second bit, and so on, producing an 8-bit result based on the AND logic for each pair of bits.

## 3. Why does it work?

Bitwise operations are very efficient at the hardware level. Processors have direct instructions for these operations, making them extremely fast. They are used for tasks that require manipulating data at the lowest level, such as controlling hardware registers, implementing low-level protocols, and optimizing certain computations.

## 4. When does this work?

Bitwise operators are used when you need fine-grained control over the individual bits of data within an integer type.

### Common Uses:

* **Setting flags**: Using **`|` (OR)** with a mask where the desired bits are `1` to set those bits in a value.
* **Clearing flags**: Using **`&` (AND)** with the **`~` (NOT)** of a mask where the bits to be cleared are `1`.
* **Checking if a flag is set**: Using **`&` (AND)** with a mask to isolate the specific bit(s) and checking if the result is non-zero.
* **Toggling bits**: Using **`^` (XOR)** with a mask where the bits to be toggled are `1`.
* **Efficient multiplication and division by powers of 2**: Using **`<<` (Left Shift)** for multiplication and **`>>` (Right Shift)** for division.
* **Working with bitmasks**: Combining multiple binary options or flags into a single integer value.

### MORE:

* **Bit Masking**: The process of selectively isolating or extracting certain bits from a value by using the bitwise AND operator (`&`) with a "mask". The mask is an integer where the bits you want to keep are set to `1`, and the bits you want to ignore are set to `0`.
* **Bit Setting**: The process of setting one or more specific bits in a value to `1` by using the bitwise OR operator (`|`) with a mask where the bits you want to set are `1`.
* **Bit Clearing**: The process of setting one or more specific bits in a value to `0` by using the bitwise AND operator (`&`) with the bitwise NOT (`~`) of a mask where the bits you want to clear are `1`.