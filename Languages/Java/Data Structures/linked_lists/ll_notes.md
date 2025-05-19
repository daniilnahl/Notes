## 1. What is a list?

A List is a collection that allows duplicates. Each element has an index and a value. There are two main types:

* **ArrayList**: Stores elements in a dynamic array.
* **LinkedList**: Stores elements as a series of nodes (each node pointing to the next).

## 2. Why use a List?

* To maintain the order of elements.
* To allow duplicates.
* To access elements by index (important for ArrayList).
* To handle frequent insertions/deletions (important for LinkedList).

## 3. How to use?

* **ArrayList**: Uses a resizable array internally. Great for random access (fast `get()`).
* **LinkedList**: Each element (node) points to the next and the previous node. Great for insertion and deletion operations.

## 4. When to use each?

* Use **ArrayList** if you need fast access by index or mostly read data.
* Use **LinkedList** if you frequently insert/delete elements from the middle or the start.

**Tips:**

* Prefer **ArrayList** for general-purpose lists.
* Avoid **LinkedList** for random access as it’s slow (O(n)).