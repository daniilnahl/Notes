# Important Note on Headers and Classes

- **Headers (aka Classes) should NOT include using declarations.**  
  If a class header is imported into a file where that `using` declaration is not present, it will cause compilation errors.

- `using namespace std;`  
  Makes all names in the `std` namespace available without the `std::` prefix.

- Even when you use a `using` declaration, **you should still specify `std::`** because:  
  1. It is a convention.  
  2. It prevents errors when two libraries have the same name for a function.
