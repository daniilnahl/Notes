# What is a selection sort?
**Selection Sort** is a comparison-based sorting algorithm. It sorts an array by repeatedly selecting the smallest (or largest) element from the unsorted portion and swapping it with the first element of the unsorted portion. This process continues until the entire array is sorted.

**Here's how it works step-by-step:**
1.  Find the minimum element in the unsorted part of the array and swap it with the first element of the unsorted part. The first element is now in its correct sorted position.
2.  Consider the remaining unsorted part of the array. Find the minimum element in this part (which will be the second smallest element overall) and swap it with the first element of this remaining unsorted part (which is the second element of the original array). The second element is now in its correct sorted position.
3.  Repeat this process, shrinking the unsorted portion from the left, until the entire array is sorted.

## What is the time complexity?
- Selection sort has a time complexity of **$O(n^2)$** in the best, average, and worst cases. This makes it significantly slower for large datasets compared to more efficient algorithms like Quick Sort or Merge Sort ($O(n \log n)$).

## What are the benefits?
- It is **easy to understand and implement**.
- It is an **in-place** sorting algorithm, requiring only a constant **$O(1)$ extra memory space** for temporary storage during swaps.
- It requires a **less number of swaps** (or memory writes) compared to many other standard comparison-based sorting algorithms like Bubble Sort or Insertion Sort. Only algorithms like Cycle Sort perform fewer writes. 

## What are the disadvantages?
- It is **not a stable sort**, meaning that if two elements have the same value, their relative order in the original array is not guaranteed to be preserved in the sorted output.

# What are applications of Selection Sort?
* It is perfect for **teaching fundamental sorting mechanisms** and algorithm design principles due to its straightforward logic.
* It is suitable for **small lists** where the $O(n^2)$ time complexity is not a significant performance bottleneck, and the overhead of more complex algorithms is not justified.
* It is useful in scenarios where **memory writes are particularly costly**, as it minimizes the number of swaps.
* The core idea of repeatedly finding the minimum element is fundamental and related to other algorithms; for example, the **Heap Sort** algorithm is based on the concept of repeatedly extracting the minimum (or maximum) element from a heap, which is a form of selection.