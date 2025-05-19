## 1. What is a set?

A Set is a collection that does not allow duplicate elements. It models a mathematical set. There are three main types:

* **HashSet**: A hash table with indexes and values that doesn't allow duplicates and has no specific order.
* **LinkedHashSet**: Same as HashSet but maintains order of insertion.
* **TreeSet**: (Red Black Tree) Elements are sorted in natural order or by a custom comparator. No null values allowed.

## 2. Why use a set?

* To ensure that only unique elements are stored.

## 3. How do sets work?

* **HashSet**: Stores elements in a hash table (fast operations, unordered). (The basic set).
* **LinkedHashSet**: Maintains insertion order.
* **TreeSet**: Stores elements in a sorted order.

## 4. When to use sets?

* Use **HashSet** for fast lookups.
* Use **LinkedHashSet** when you need insertion order.
* Use **TreeSet** for sorted data.

**Tips:**

* Use **HashSet** for most scenarios.
* Avoid **TreeSet** for large datasets as sorting can be slow.