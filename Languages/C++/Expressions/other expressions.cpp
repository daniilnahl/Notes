#include <iostream>
using namespace std;

int main() {
    //size of 
    int a[] = {5,4,3,2,1};
    //returns the number of elements in a
    cout << sizeof(a) / sizeof(*a) << endl;
    
    //comma operator
    int x = 0, b = 1, c =2;
    x++, b--, c++;

    cout << x << b << c << endl;

    //arithmetic conversions
    bool flag; char cval;
    short sval; unsigned short usval;
    int ival; unsigned int uival;
    long lval; unsigned long ulval;
    float fval; double dval;
    3.14159L + 'a'; // ’a’ promoted to int, then that int converted to long double
    dval + ival; // ival converted to double
    dval + fval; // fval converted to double
    ival = dval; // dval converted (by truncation) to int
    flag = dval; // if dval is 0, then flag is false, otherwise true
    cval + fval; // cval promoted to int, then that int converted to float
    sval + cval; // sval and cval promoted to int
    cval + lval; // cval converted to long
    ival + ulval; // ival converted to unsigned long
    usval + ival; // promotion depends on the size of unsigned short and int
    uival + lval; // conversion depends on the size of unsigned int and long
    return 0;
}