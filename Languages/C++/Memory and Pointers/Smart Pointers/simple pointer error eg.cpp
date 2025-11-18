#include <memory>
#include <iostream>

int main() {

    int* p = new int(42);

    // Use it just like a normal pointer
    std::cout << "Value is: " << *p << "\n";

   //code belows frees up the memory preventing a leak
    delete p;
    p = nullptr;

     if (p) {
        std::cout << *p << "\n";
    } else {
        std::cout << "p is null—no object to use.\n";
    }
    
    return 0;
}
