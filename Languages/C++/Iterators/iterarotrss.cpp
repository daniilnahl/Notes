#include <iostream>
#include <vector>
using namespace std;

int main() {

    string s = "ilove my girlfriend";
    
    // process characters in s until we run out of characters or we hit a whitespace
    for (auto it = s.begin(); it != s.end() && !isspace(*it); ++it)
        *it = toupper(*it); // capitalize the current character

    cout << s << endl;

    //vector iterator
    vector<int> numbers = {1, 2, 3, 4, 5};
    //iterator behaves like pointer
    for(vector<int>::iterator a = numbers.begin(); a != numbers.end(); a++){
        *a *= 2; //accessing the value the iterator is pointing to, just like dereferencing a pointer.
        // allows you to access and modify the value stored at the current position of the iterator.
    }

    for(auto asd : numbers){
        cout << asd << endl;
    }
    //vector const iterator
    for (vector<int>::const_iterator it3 = numbers.begin(); it3 != numbers.end(); ++it3) {
        cout << *it3 << " "; // Output: 1 2 3 4 5
    }
    // *it3 = 10; // Error: cannot modify elements

    //string iterator
    string text = "hello";
    for (string::iterator it2 = text.begin(); it2 != text.end(); ++it2) {
        if (*it2 == 'l') *it2 = 'L'; // Modify characters
    }
    cout << text << endl;

    //string const interator
    text = "hello";
    for (std::string::const_iterator it4 = text.begin(); it4 != text.end(); ++it4) {
        std::cout << *it4; // Output: hello
    }
    // *it4 = 'H'; // Error: cannot modify characters
    return 0;
}