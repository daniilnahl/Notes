# 1. What is a Map?

A **Map** is similar to a Python dictionary. It holds a set of **unique keys** and a collection of **values**; each key is associated with exactly one value.

### Basic Functions

* `put(key, value)` – Adds a mapping.
* `get(key)` – Retrieves the value mapped to the key.
* `remove(key)` – Removes the key and its associated value.
* `.keySet()` – Used in loops to iterate over keys:

```java
for (String key : map.keySet()) {
    // code using key
}
```
There are four main types of maps:

1.  **Hash Map** - Stores keys and values in a hash table. Doesn't guarantee an order of keys. Allows ONE null key.
2.  **Linked Hash Map** - Same as hash map but maintains the order in which keys were added.
3.  **Tree Map** - A map (python dictionary) that sorts keys in natural order or using a custom comparator. NO null keys allowed.
4.  **Hashtable** - Same as hash map, but it's synchronized (thread safety), which means that only one thread at a time can work with the hashtable. If there are multiple threads in the program doing stuff to the hashtable at the same time, Java makes sure they don't interfere with each other.

## 2. Why use maps?

* To associate keys with values (e.g., a dictionary or phone book).
* To retrieve a value quickly using a key.

## 3. How do maps work?

* **HashMap**: Stores key-value pairs in a hash table (unordered, fast).
* **LinkedHashMap**: Maintains insertion order.
* **TreeMap**: Stores key-value pairs in sorted key order.

## 4. When to use each type?

* Use **HashMap** for fast lookups.
* Use **LinkedHashMap** for maintaining order.
* Use **TreeMap** for sorted keys.