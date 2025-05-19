# Vectors in C++

## 1. What are Vectors?  
A dynamic array that can grow or shrink in size automatically. It stores elements of the same type in contiguous memory, supports random access, and provides flexible operations like insertion, deletion, and resizing with better performance compared to traditional arrays for such tasks.  
Essentially like a Python list but only holds one type per vector (template-based, type must be specified).

---

## 2. Ways to Initialize a Vector  
- `vector<T> v1`  
  Default initialization; `v1` is empty.  
- `vector<T> v2(v1)`  
  `v2` is a copy of each element in `v1`.  
- `vector<T> v2 = v1`  
  Equivalent to `v2(v1)`, a copy of elements in `v1`.  
- `vector<T> v3(n, val)`  
  `v3` has `n` elements initialized to `val`.  
- `vector<T> v4(n)`  
  `v4` has `n` copies of a value-initialized object.  
- `vector<T> v5{a, b, c, ...}`  
  `v5` has as many elements as initializers; elements initialized correspondingly.  
- `vector<T> v5 = {a, b, c, ...}`  
  Equivalent to `v5{a, b, c, ...}`.

---

## 3. Vector Operations  
- `v.empty()`  
  Returns `true` if `v` is empty; otherwise `false`.  
- `v.size()`  
  Returns the number of elements in `v`.  
- `v.push_back(t)`  
  Adds an element with value `t` to the end of `v`.  
- `v[n]`  
  Returns a reference to the element at position `n` in `v`.  
- `v1 = v2`  
  Replaces the elements in `v1` with a copy of the elements in `v2`.  
- `v1 = {a, b, c, ...}`  
  Replaces elements in `v1` with a copy of elements in the comma-separated list.  
- `v1 == v2`, `v1 != v2`  
  `v1` and `v2` are equal if they have the same number of elements and each corresponding element is equal.  
- `<, <=, >, >=`  
  Normal dictionary ordering comparisons.  
- `sort([name].begin(), [name].end())`  
  Sorts values from beginning to end in a vector.
