## What is a generator?
    Special type of iterator that allows you to yield values one at a time using the yield keyword, producing items only when requested (lazy evaluation). 
    Generators are memory-efficient and are created by defining a function with yield instead of return, or by using generator expressions.
    Everything you can do with a generator you can do with an iterator, however sometimes its easier to use a generator.

## Why use a generator?
    Generators are useful for handling large datasets or streams of data, as they generate items one at a time and only when needed, making them memory-efficient. 
    They also allow for cleaner, more readable code for certain iterative tasks.

## When to use a generator?
    Real-World Example:
        A situation where generators can help is when dealing with I/O. A stream of
        data coming from a network service can be represented by a generator that yields the available data
        until the stream is closed when it returns the remaining data. Using a generator allows the program
        to pass control back and forth between the I/O stream when data is available, and the caller where
        the data can be processed.

## How to use a generator?
    Example of usage in .py file.