#include <iostream>
#include <stdexcept>
using namespace std;
//throw is used to throw an exception when a problem shows up. Example:
int divide(int a, int b) {
    if (b == 0) {
        throw runtime_error("Division by zero!");
    }
    return a / b;
}
int main() {
    //general form of try block
    try {
        cout << 20 << endl;
    } catch (int e) { //catch block - where you put the exception handler code
        cout << "An exception occurred. Exception Nr. " << e << endl;
    }

    // divide(10, 0);
    int x;
    cout << "Enter age: ";
    cin >> x;

    try {
        if (x == 68){
            throw "You are too old"; //throwing a string exception and is caught by string catch
        }
        else if (x >= 18 && x <= 67) {
            cout << "Access granted - you are old enough.";
        } 
        else {
            throw x; //throwing an int exception and  is caught by int catch 
        }
    }
    catch (const char* msg) {
        cout << msg << endl;
        }
    catch (int y) {
        cout << "Access denied - You must be sigma.\n";
    }
    return 0;
}