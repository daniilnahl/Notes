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
//template function can have a default argument
int max(int x, int y=1) //'template' with defined types, use only when needed for specific implementation
{
    std::cout << "defined type function";
    return (x < y) ? y : x;
}

template <> //telling complier that instantiation of function templates with certain arguments should be disallowed using a function template
const char* max(const char* x, const char* y){
    return "Error: can't use const char* parameters in max()"; //dont do this because it will still allow the program to run with a faulty output. INSTEAD DO WHATS BELOW!!!
}
/***
 * const char* addOne(const char* x) = delete; - the delete message tells complier that it should send a compilation error.
 */

template <typename A, typename B>
auto useful_max(A x, B y){
    return (x < y) ? y : x;
}
/***c++ 20 shortcut for function above - called: abbreviated function template
auto max(auto x, auto y)
{
    return (x < y) ? y : x;
}
***/

//TEMPLATES can also be overloaded
template <typename T>
auto add(T a1, T a2) { 
    return a1+a2;
}

template <typename T, typename U>
auto add(T a1, U a2) { 
    return a1+a2;
}

template <typename T, typename U, typename X>
auto add(T a1, U a2, X a3) { 
    return a1+a2+a3;
}

int main(){
    std::cout << "subtract function" << std::endl;
    std::cout << subtract(15, 20) << std::endl;
    std::cout << subtract(15.85, 20.50) << std::endl;
    std::cout << "max function" << std::endl;
    std::cout << max<>(10, 5) << std::endl; //in my case <> calls the template function. Without '<>' the defined type function will be called
    std::cout << max(10.0, 5.0) << "\n\n\n"<< std::endl;
    // std::cout << max(16, 5.5) << std::endl; 
    // would cause a compile error because compiler will try to make both those parameters type T but type T cant be both an integer and double at the same time.
    // To fix this error make a template with two unique typename parameters.

    std::cout << useful_max(5, 6.5) << "\n\n\n\n"; //auto detected the type of the return variable.

    //function overload example
    std::cout << add(5, 5) << std::endl;
    std::cout << add(15, 20.9) << std::endl;
    std::cout << add(15, 20, 23.5) << std::endl;

    return 0;
}