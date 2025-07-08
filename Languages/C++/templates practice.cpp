#include <iostream>
template <typename T>
int subtract(T a1, T a2) { //when I will use this function with different data types the complier will decide what type to bind to the template based on the type of parameters passed into the function
    return a1-a2;
}

int main(){
    std::cout << subtract(15, 20) << std::endl;
    std::cout << subtract("asa", "asd") << std::endl;
    std::cout << subtract('a', 'a') << std::endl;

    return 0;
}