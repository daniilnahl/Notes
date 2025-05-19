## 1. What is merge sort?

**Merge Sort** is a **Divide and Conquer** sorting algorithm with a time complexity of **$O(n \log n)$**. It repeatedly divides the data in half, recursively sorts each half, and then combines the sorted halves into a single sorted whole.

## 2. How does it work?

Merge Sort works recursively through these steps:

1.  **Divide**: Divide the unsorted list into two roughly equal halves.
2.  **Sort**: Recursively sort the left half.
3.  **Sort**: Recursively sort the right half.
4.  **Merge**: Merge the two sorted halves into one sorted list.

This process continues until the list is broken down into individual elements (which are considered sorted), and then the merging process builds the sorted list back up.

## 3. Why is merge sort cool?

* **Guarantees the same time complexity** for all cases (best, average, and worst), consistently performing at $O(n \log n)$.
* It is a **stable sort**, meaning it preserves the relative order of equal elements.
* It is particularly useful for sorting **linked lists** due to efficient merging without requiring the shifting of elements that arrays need.

## 4. When to use merge sort?

* When you need to sort large, unordered datasets quickly and reliably.
* When **stability** (preserving the order of equal elements) is a requirement.
* When sorting data structures where random access is expensive but sequential access and merging are efficient, such as linked lists.