#include <iostream>

template <typename T>
T subtract(T a1, T a2) { //when I will use this function with different data types the complier will decide what type to bind to the template based on the type of parameters passed into the function
    return a1-a2;
}

template <typename U> //template
U max(U x, U y) { //when I will use this function with different data types the complier will decide what type to bind to the template based on the type of parameters passed into the function
    std::cout << "template function";
    return  (x < y) ? y : x;
}

int max(int x, int y) //'template' with defined types, use only when needed for specific implementation
{
    std::cout << "defined type function";
    return (x < y) ? y : x;
}

template <> //telling complier that instantiation of function templates with certain arguments should be disallowed using a function template
const char* max(const char* x, const char* y){
    return "Error: can't use const char* parameters in max()"; //dont do this because it will still allow the program to run with a faulty output. INSTEAD DO WHATS BELOW!!!
}
/***
 * const char* addOne(const char* x) = delete;
 */
int main(){
    std::cout << "subtract function" << std::endl;
    std::cout << subtract(15, 20) << std::endl;
    std::cout << subtract(15.85, 20.50) << std::endl;
    std::cout << "max function" << std::endl;
    std::cout << max<>(10, 5) << std::endl; //in my case <> calls the template function. Without '<>' the defined type function will be called
    std::cout << max(10.0, 5.0) << std::endl;
    std::cout << max(16, 5) << std::endl;

    std::cout << max("Hell", "oa") << '\n'; // compile error


    // std::cout << subtract("asa", "asd") << std::endl;
    // std::cout << subtract('a', 'a') << std::endl;

    return 0;
}