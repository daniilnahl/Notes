#include <sstream>
#include <string>
#include <iostream>
using namespace std;

int main(){
    string s1 = " I lovve potatoes";
    string s2 = "i love cooking potatoes";
    stringstream ss1(s1), ss2(s2);
    /*** 
    What is stringstream?
    stringstream is a C++ stream class from <sstream> that lets you treat a string as 
    if it were an input/output stream, enabling formatted extraction (>>) and insertion (<<) of data, similar to how you interact with cin and cout.

    How does stringstream work?
    It wraps an internal string buffer and uses the same stream extraction/insertion operators as other standard streams. 
    When reading (>>), it parses the internal string according to stream rules—tokenizing by whitespace for strings, or parsing into numbers as needed. When writing (<<), 
    it appends formatted text into the buffer. The buffer can be set or retrieved at any time via the constructor, str(), or clear() methods.

    Why does it work?
    It works because stringstream inherits from both istream and ostream via iostream, and internally manages a stringbuf—a specialized buffer that holds string data. 
    The stream extraction/insertion operators operate on this buffer, making it possible to reuse all the formatting, parsing, and delimiter-handling logic of C++’s stream library without manually writing tokenization or formatting code.
    **/
    string temp;
    while (ss1 >> temp){ //stringstream automatically tokenizes each word. (default is space, newline, tab)
        cout << temp << endl;

    }

     while (ss2 >> temp){ //stringstream automatically tokenizes each word. (default is space, newline, tab)
        cout << temp << endl;

    }


    return 0;
}