# Dynamic Memory Allocation in C

## 1. What is it?

Dynamic memory allocation is a process by which a program can request memory from the operating system's heap during runtime, as needed.  
Standard C library functions used for this purpose include:

- `malloc()`
- `calloc()`
- `realloc()`
- `free()`

## 2. How does it work?

### `calloc(n, m)`
- Allocates `n` elements, each of size `m` bytes.
- Initializes memory to zero.
- Returns pointer to the start of the memory block or `NULL`.

### `malloc(size)`
- Allocates a block of `size` bytes.
- Memory is **not** initialized.
- Returns pointer to the start of the memory block or `NULL`.

### `free(ptr)`
- Deallocates memory pointed to by `ptr`.
- No return value.

### `realloc(ptr, size)`
- Changes the size of memory pointed to by `ptr` to `size`.
- Returns pointer to new memory (start of the block) or `NULL`.

## 3. Why does it work?

The operating system manages a large pool of memory called the **heap**. When a program calls one of the allocation functions, the OS:

- Searches for a suitable contiguous block of free memory.
- Marks it as allocated to the program.
- Maintains internal structures to track allocated/free memory blocks.

Calling `free()` informs the OS that a specific memory block is no longer needed, allowing it to be reused.

## 4. When does this work?

Dynamic memory allocation is used when:

- The amount of memory required is unknown at compile time.
- Memory needs to persist beyond the lifetime of a single function.

---

## MALLOC vs CALLOC

| Feature | `malloc()` | `calloc()` |
|--------|-------------|------------|
| Initialization | Does **not** initialize memory | Initializes memory to **zero** |
| Parameters | Number of bytes | Number of elements and size per element |
| Usage Risk | You must calculate total size correctly | Automatically calculates total size |

**Note:**  
- `calloc(n, m)` = allocates `n * m` bytes and initializes to zero.  
- `malloc(size)` = allocates `size` bytes (no initialization).  
  If you miscalculate `size`, your program may crash or exhibit undefined behavior.

---

## TIPS

- Always check the return value of `malloc()`, `calloc()`, and `realloc()` to ensure allocation was successful (i.e., not `NULL`).
- Always call `free()` on any dynamically allocated memory when you're done using it to prevent memory leaks.
- Use caution with `realloc()`:
  - If it fails, it returns `NULL`, but the original memory block remains valid.
  - Always store the result of `realloc()` in a **temporary pointer** to avoid losing the original pointer in case of failure.
