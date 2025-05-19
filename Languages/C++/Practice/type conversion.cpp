#include <iostream>
#include <string>
using namespace std;

// Given n, take the sum of the digits of n. If that value has more than one digit, continue reducing in this way until a single-digit number is produced. The input will be a non-negative integer.
int digital_root(int n){
    return 1 + ((n - 1) % 9); //digital root formula
}

int main() {
    //int to string
    int num = 0;
    string m = to_string(num);

    int as = digital_root(777);
    cout << as << endl;
    cout << 12/10 << endl;
    cout << 9 % 10 << endl;

    //string to int
    string str_num = "12345";
    int int_num;
    int_num = stoi(str_num);
    cout << "Integer value: " << int_num << endl;

    //char to int
    char digitChar = '7';
    int digitInt = digitChar - '0';
    cout << "The integer value of " << digitChar << " is " << digitInt << endl;
 
    return 0;
}

