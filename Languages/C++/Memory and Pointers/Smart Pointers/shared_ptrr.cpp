//gui widget tree
#include <memory>
#include <vector>
#include <string>
#include <iostream>

struct Widget {
    std::string name;
    std::vector<std::shared_ptr<Widget>> children;
    Widget(const std::string& n): name(n) {}
    void addChild(std::shared_ptr<Widget> w) {
        children.push_back(std::move(w));
    }
};

int main() {
    auto root = std::make_shared<Widget>("Window");
    auto btn  = std::make_shared<Widget>("Button");
    root->addChild(btn);

    std::cout << "The amount of owners for the memory address that root is pointing to is: " << root.use_count() << std::endl;
    std::cout << "The amount of owners for the memory address that btn is pointing to is: " << btn.use_count() << std::endl; 

        std::cout << &btn << std::endl; 


    // Both `root` and `btn` share ownership of the button widget.
}
