#include <iostream>
#include <string>
#include "class_prac_1.h"
using namespace std;

int main(){
    int i = 100, sum = 0;
    for (int i = 0; i != 10; ++i){
        sum += i;
    }
    //references
    int &reftotal_sum = sum;
    int &r = i;
    cout <<  r << endl;
    cout <<  reftotal_sum << endl;
    //pointers
    int *ip1;
    ip1 = &i;
    void *as = &sum; //look at this. It works without declaring the type unlike ip1.
    cout << ip1 << endl; //prints the address
    cout << *ip1 << endl; //prints the actual value

    //example of multi level pointers
    int ival = 1024;
    int *pi = &ival; // pi points to an int
    int *&ref_ex = pi; //reference

    int **ppi = &pi;// ppi points to a pointer to an int
    int **&ref_example = ppi; //reference
    cout << ref_example << endl;

    const int FOREVER_NUMBER = 0; //const makes the number unchangeable 
    const int bufSize = 512; //real world example of const

    //typedef example
    typedef double wages; // wages is a synonym for double
    wages micheal = 12.11, sofia = 14.334;
    cout << micheal + sofia << endl;

    //typedef example pointer
    typedef char *pstring;
    const pstring cstr = 0; // cstr is a constant pointer to char
    const pstring *ps; // ps is a pointer to a constant pointer to char

    //neat feature auto
    // figures out the type for item automatically based on types of val1 and val2
    int val1 = 1;
    int val2 = 2;
    auto item = val1 + val2; // item initialized to the result of val1 + val2
    

    //end of chapter practice
    class_prac_1 data1, data2;
    
    double price = 0;
    cin >> data1.bookNo >> data1.units_sold >> price;
    data1.revenue = data1.units_sold * price;
    cout << data1.revenue << endl; 
    // cerr << "boob" << endl; error output
    

    return 0;
}