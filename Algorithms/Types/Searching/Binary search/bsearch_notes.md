## 1. What is Binary Search?

A search algorithm that efficiently finds a target value in a **sorted array**. With each iteration, half the remaining search space is eliminated. The runtime for Binary Search is typically $O(\log n)$.

**Conditions to use binary search:**

* The data structure must be sorted.
* Access to any element of the data structure should take constant time (e.g., an array).

## 2. How to use Binary Search?

When approaching a problem where Binary Search might apply, ask yourself this:

1.  What exactly are you searching for?
2.  How are you searching for it (based on the sorted nature)?
3.  Does this approach make sense for the specific problem constraints and data structure?

## 3. When to use Binary Search?

* The data is **sorted**: Binary search works only on sorted collections (like arrays).
* You are searching for a specific element: You need to find the position of or check for the existence of a particular value or condition.
* Efficiency is key: The problem requires faster-than-linear solutions (better than just looping through all elements).

## 4. What are advantages of binary search?

* Binary search is significantly faster than linear search, especially for large arrays.
* It can be more efficient than other searching algorithms with a similar theoretical time complexity in practice, depending on the constant factors and data distribution.
* Binary search is well-suited for searching large datasets that are stored in data structures allowing constant-time random access and are sorted.

## 5. What are disadvantages of binary search?

* The array **must be sorted** beforehand, which adds an initial cost if the data is not already sorted.
* Binary search traditionally requires the data structure to be stored in contiguous memory locations (like an array) for efficient random access.
* Binary search requires that the elements of the array be comparable, meaning that they must have a defined order.

## 6. What are applications of binary search?

* **Finding elements in sorted arrays or lists**: Its most direct application.
* **Finding a specific value in a database index**: Databases often use structures that allow binary search.
* **Root finding or solving equations**: Using binary search on a sorted range of values to find where a function crosses zero.
* **Building block in more complex algorithms**: Used within algorithms for training neural networks, finding optimal hyperparameters, or in algorithms for computer graphics (like ray tracing or texture mapping) where searching sorted data is involved.