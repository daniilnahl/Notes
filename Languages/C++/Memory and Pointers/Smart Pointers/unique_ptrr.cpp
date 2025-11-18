#include <memory>
#include <iostream>

int main() {
    // Create a unique_ptr owning a new int initialized to 42
    std::unique_ptr<int> p = std::make_unique<int>(42);

    // Use it just like a normal pointer
    std::cout << "Value is: " << *p << "\n";

    // Transfer ownership to another unique_ptr
    std::unique_ptr<int> q = std::move(p);
    
    if (!p) {//check for p to be empty
        std::cout << "p is now empty; q owns the int with value " << *q << "\n";
    } else{
        std::cout << "p is not empty" << std::endl;
    }

    // When q goes out of scope here, the int is deleted automatically.
    return 0;
}
