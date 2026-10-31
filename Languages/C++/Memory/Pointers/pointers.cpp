#include <iostream>
using namespace std;

int main() {
    //using a pointer to iterate through an array
    int arr[] = {0,1,2,3,4,5,6,7,8,9};
    int *p = arr; // p points to the first element in arr
    ++p; // p points to arr[1]

    //another example
    constexpr size_t sz = 5;
    int arr[sz] = {1,2,3,4,5};
    int *ip = arr; // equivalent to int *ip = &arr[0]
    int *ip2 = ip + 4; // ip2 points to arr[4], the last element in arr

    //while loop 
    int *b = arr, *e = arr + sz; //sz is size of arr so it e points to the last element of arr
    while (b < e) {
    // use *b
    ++b;
    }

    int ia[] = {0,2,4,6,8}; // array with 5 elements of type int
    int last = *(ia + 4); // ok: initializes last to 8, the value of ia[4]
    // The expression *(ia + 4) calculates the address four elements past ia and dereferences
    // the resulting pointer. This expression is equivalent to writing ia[4].
    return 0;
}