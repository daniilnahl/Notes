## 1. What are these things?

* **Structure (struct)**: A user-defined data type that allows you to bundle variables of different data types together under a single name. These variables are called **members** of the structure. Each member occupies its own unique memory location within the structure, and all members can hold values simultaneously.

* **Union (union)**: A user-defined data type that also allows you to bundle variables of different data types under a single name. However, unlike structures, all members of a union **share the same memory location**. This means that only one member of a union can hold a value at any given time. The size of the union is determined by the size of its largest member. Only one "member" (variable) can hold a value at a specific time.

## 2. Why do they work this way?

* **Structures**: They work by allocating **contiguous memory** for *all* their members. The total size of a structure is typically the sum of the sizes of its members (though compilers may add padding for data alignment). This design allows you to treat a collection of related data items as a single logical unit.

* **Unions**: They work by allocating enough memory to accommodate only the **largest** of their members. All members are then stored at the **same starting memory address**. When you assign a value to one member, that memory location is interpreted according to the data type of that member, which will overwrite whatever was previously stored there by another member. This is useful when you have a piece of data that can be one of several types, but you only need to access one type at a time, thereby saving memory.

## 3. When does this work?

### 1. Structures

* **Representing records**: Ideal for grouping related pieces of information that logically belong together, such as the properties of an object (e.g., a `Person` with `name`, `age`, `address`) or coordinates (`Point` with `x`, `y`).
* **Creating complex data types**: Used as building blocks for more intricate data structures like linked lists, trees, and graphs, where structure members often include pointers to other structures of the same or different types.
* **Passing multiple values to functions**: Allows you to pass a collection of related values to a function as a single argument, simplifying function signatures compared to passing numerous individual parameters.

### 2. Unions

* **Saving memory**: Primarily used when memory is constrained and you know that only one out of a set of different data types will be active or needed at any single point in time for the same data instance.
* **Type punning (use with caution)**: Can be used to reinterpret the raw bits of one data type as another data type. This is a low-level technique that is often platform-dependent and should be used with extreme care due to potential for undefined behavior if violated.
* **Implementing tagged unions**: Often combined with an `enum` (enumeration) variable that indicates which member of the union is currently holding valid data. This creates a "tagged union" which provides a safer way to use unions by explicitly tracking the active type.