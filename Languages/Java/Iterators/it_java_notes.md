# 1. What is an Iterator?

An **iterator** is an object used to traverse (iterate over) a collection one element at a time.

# 2. Why Use an Iterator?

- To loop through a collection without worrying about its specific type (e.g., `ArrayList`, `LinkedList`, `Set`, etc.).
- To **safely remove** elements during iteration — avoids `ConcurrentModificationException`, which occurs when a collection is modified while being iterated through by a thread.

# 3. How Does It Work?

- `hasNext()`: Checks if more elements are available.
- `next()`: Retrieves the next element.
- `remove()`: Removes the last element returned by `next()`.

# 4. When to Use an Iterator?

Use an iterator when:

- You want to iterate over a collection **generically**.
- You need to **modify** elements during iteration.

# ✅ Tips

- Use **for-each** loop for simpler traversal unless you need to remove elements:
  ```java
  for (dataType variable : arrayOrCollection) {
      // code to be executed for each element
  }
