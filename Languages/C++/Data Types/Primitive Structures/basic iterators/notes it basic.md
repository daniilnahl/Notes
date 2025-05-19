# Iterators

Iterators behave like pointers, so you need to dereference them to access the value.

---

## 1. Iterator Types  
- `vector<int>::iterator it;`  
  Can read and write `vector<int>` elements.  
- `string::iterator it2;`  
  Can read and write characters in a string.  
- `vector<int>::const_iterator it3;`  
  Can read but not write elements.  
- `string::const_iterator it4;`  
  Can read but not write characters.

---

## 2. Operations Supported by Vector and String Iterators  
- Adding (or subtracting) an integral value `n` to (or from) an iterator yields an iterator `n` elements forward (or backward) within the container. The resulting iterator must denote elements in, or one past the end of, the same container:  
  - `iter + n`  
  - `iter - n`

- Compound-assignment for iterator addition and subtraction. Assigns to `iter1` the value of adding or subtracting `n`:  
  - `iter1 += n`  
  - `iter1 -= n`

- Subtracting two iterators yields the number that when added to the right-hand iterator yields the left-hand iterator. The iterators must denote elements in, or one past the end of, the same container:  
  - `iter1 - iter2`

- Relational operators on iterators. One iterator is less than another if it refers to an element that appears in the container before the one referred to by the other iterator. The iterators must denote elements in, or one past the end of, the same container:  
  - `>`, `>=`, `<`, `<=`
