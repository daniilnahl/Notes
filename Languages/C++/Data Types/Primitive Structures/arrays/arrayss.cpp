#include <iostream>
#include <iterator>
using namespace std;

int main() {

    const unsigned sz = 10;
    int arr[sz] = {0,1,2,3,4,5,6,7,8,9}; // array of three ints with values 0, 1, 2


    cout << sizeof(arr) << endl; //returns size in bytes.
    cout << size(arr) << endl;


    int a2[] = {0, 1, 2}; // an array of dimension 3
    int a3[5] = {0, 1, 2}; // equivalent to a3[] = {0, 1, 2, 0, 0}
    string a4[3] = {"hi", "bye"}; // same as a4[] = {"hi", "bye", ""}
    // int a5[2] = {0,1,2}; // error: too many initializers

    //complicated array declarations
    int *ptrs[10]; // ptrs is an array of ten pointers to int
    // int &refs[10] = /* ? */; // error: no arrays of references
    
    //THIS IS COOL. Array type specificly for pointers and references
    int (*Parray)[10] = &arr; // Parray points to an array of ten ints
    int (&arrRef)[10] = arr; // arrRef refers to an array of ten ints

    for (auto c : arr){
        cout << c << endl;
    }
    cout << "_______________________________" << endl;
    cout << "_______________________________" << endl;
    cout << "_______________________________" << endl;

    //multi dimensional arrays
    int ia[3][4] = { // three elements; each element is an array of size 4
    {0, 1, 2, 3}, // initializers for the row indexed by 0
    {4, 5, 6, 7}, // initializers for the row indexed by 1
    {8, 9, 10, 11} // initializers for the row indexed by 2
    };

    int (&row)[4] = ia [1];

    for(auto a : row){
        cout << a << endl;
    }

    //nested for loop to assign values to elements
    constexpr size_t row2 = 3, col2 = 4;
    size_t cnt = 0;
    int aaa[row2][col2];

    // for each row
    for (auto &row : ia) {
    // for each column within the row
        for (auto &col : row) {
        // assign the element’s positional index as its value
            col = cnt;
            cnt++;
        }
    }

    // We write auto reference in order to avoid the normal array to
    // pointer conversion. If row is not a reference, when the
    // compiler initializes row it will convert each array element (like any other object of
    // array type) to a pointer to that array’s first element. As a result, in this loop the
    // type of row is int*. The inner for loop is illegal. Despite our intentions, that loop
    // attempts to iterate over an int*.

    int (*p)[4] = ia; // p points to an array of four ints
    p = &ia[2]; // p now points to the last element in ia

    //!!!!!!!!!!!The parentheses in this declaration are essential:!!!!!!!!!!!!!!
    int *ip[4]; // array of pointers to int
    int (*iddd)[4]; // pointer to an array of four ints
    return 0;
}