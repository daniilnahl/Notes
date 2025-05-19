#include <iostream>
#include <cstring>
using namespace std;

int main() {
    const char ca1[] = "A string example";
    const char ca2[] = "A different string";
    
    if (strcmp(ca1, ca2) < 0) {
        cout << "your mom " << endl;
    }
    else {
        cout << "your dad" << endl;
    }

    //
    return 0;
}