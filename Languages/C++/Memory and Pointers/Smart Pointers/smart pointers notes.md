# What is a Smart Pointer?
Basically, a smart pointer is able to deallocate its memory when smart pointer object is destroyed, goes out of scope or is reset. In comparison to standard pointer where user must manually deallocate it to prevent a leak.

Smart pointers use RAII aka "Resource Acquisition Is Initialization".

There are three types:
- **unique_ptr** - pointer that owns a unique address. Its assigned to one specific object and when pointer is destroyed or reset the object is deleted. To assign it a new value you must move() it.
- **shared_ptr** - pointer that point to a single address but has many owners, eg. objects or functions. It holds a reference num of owners thats once dropped to 0 leads to the pointer being deleted.
- **weak_ptr** - allows you to peek at whatever address without assigning ownership.

# Why use a Smart Pointer?
There are three major benefits to using a smart pointer:
- Automatic memory deallocation: eliminates most memory leaks by tying lifetime of allocations to C++ object scope.
- Helps prevent double‑deletions and dangling pointers(when pointer is pointing to a memory thats has been deallocated) by enforcing clear ownership rules (unique vs shared vs non‑owning).
- shared_ptr lets multiple parts of your program share an object safely without manual ref‑counting or custom cleanup logic.



# When to use a Smart Pointer?
1. Use 'unique_ptr' when:
- You have single ownership of a resource.
- You want strict transfer of ownership (no accidental copies).
- You want zero overhead beyond a raw pointer.
2. Use 'shared_ptr' when:
- You need shared ownership: multiple parts of your code hold references.
- You can tolerate a small atomic reference‑counting cost.
3. Use 'weak_ptr' when:
- You want a non‑owning reference to a shared_ptr’d object.
- You need to break cyclical references (e.g., parent↔child).
- You want to test “is it still alive?” before using it.