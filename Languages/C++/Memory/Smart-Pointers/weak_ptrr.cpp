#include <memory>
#include <iostream>

int main() {
    // Create a shared_ptr owning an int with value 100
    auto sp = std::make_shared<int>(100);
    
    // Create a weak_ptr observing the same int (no ownership)
    std::weak_ptr<int> wp = sp;
    
    // At this point, use_count() is 1
    std::cout << "shared count = " << sp.use_count() << "\n";

    // Lock the weak_ptr to get a shared_ptr for safe access
    if (auto locked = wp.lock()) {
        std::cout << "Value through weak_ptr: " << *locked << "\n";
    } else {
        std::cout << "Object already destroyed\n";
    }

    // Reset the owning shared_ptr → object is destroyed (count drops to 0)
    sp.reset();

    // Now wp.lock() will return nullptr
    if (wp.expired()) {
        std::cout << "After sp.reset(), weak_ptr reports expired\n";
    }
    return 0;
}
