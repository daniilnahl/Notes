## 1. What is insertion sort?

Insertion sort is a comparison-based algorithm that builds the final sorted array one item at a time. It works by inserting each new element into its proper position within the already sorted portion of the array.

## 2. How does insertion sort work?

The algorithm proceeds as follows:

1.  It starts from the second element of the array.
2.  It compares this element with the elements before it.
3.  If an element before it is larger, it shifts that larger element one position to the right.
4.  This shifting continues until the correct position for the current element is found, and the element is then inserted into that position. The process is repeated for the remaining unsorted elements.

## 3. Why is it useful?

* It is efficient for small datasets.
* It is simple to implement.
* It is an in-place sorting algorithm (requires minimal extra space).

## 4. When to use it?

* Best for **small datasets** (e.g., typically recommended for arrays with less than 20-50 elements, though the exact threshold varies).
* When the data is **nearly sorted**; Insertion Sort performs very well in this scenario.
* In real-time systems where minimal overhead and simple implementation are crucial.
* As a component in more complex sorting algorithms, like the hybrid Timsort.