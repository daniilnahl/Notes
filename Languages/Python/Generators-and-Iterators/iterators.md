### What allows comprehensions to exist in python?
    Iterators. Supporting iterators in your classes opens them up for use in comprehensions,
    for…in loops, and anywhere that Python works with collections. Your collection must implement
    a method called __iter__(), which returns the iterator. 

    The iterator also must provide a single method __next__() which returns the next value in the collection when iterator is called.
    


---

Related: [List Comprehension](../Data-Structures/list-comprehension.md) · [Generators](generators.md)

[Subject index](../index.md) · [Home](../../../README.md)
