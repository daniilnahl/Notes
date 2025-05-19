## 1. What is divide and conquer?

Divide and Conquer is a powerful problem-solving technique. It revolves around a problem being broken down into easy-to-solve small subproblems, solving those subproblems, and then combining their solutions for the main problem answer.

The technique typically involves three steps:

1.  **Divide**: The original problem is divided into smaller, typically independent subproblems. These subproblems should ideally be simpler versions of the original problem.
2.  **Conquer**: Each subproblem is solved. If a subproblem is still too large or complex, the process is applied recursively to divide it further.
3.  **Combine**: The solutions to the subproblems are merged or combined to form the solution to the original problem.

## 2. How to use it?

**Example: Merge Sort**

1.  **Divide**: Split the array into two halves.
2.  **Conquer**: Recursively sort each half.
3.  **Combine**: Merge the two sorted halves to produce the final sorted array.

This approach is efficient because dividing the problem reduces its size exponentially, and combining sorted arrays is relatively straightforward.

## 3. Why use it?

* It simplifies complex problems by dealing with smaller, manageable pieces.
* It is often more efficient than tackling the whole problem at once (e.g., logarithmic or linearithmic improvements in algorithms).
* Many algorithms like binary search, quicksort, and merge sort use this paradigm.