#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

bool is_y(char c) {
  return (c == 'y');
}

int main(){
    string mom = "best mom in world";
    string mom10 (10, 'A'); //works only for char ('')
    cin >> mom;

    return 0;
    string word;
    while(cin >> word){//cool (reads until end of file) never ending loop
        cout << word << endl;
        break;
    }

    while(getline(cin, word)){//example of getline
        cout << word << endl;
        break;
    }

    auto len = word.size(); //the number it returns is not int, its size_type. Which is a companion type of string. 

    //processing every character in a string
    string abc = "abc";
    for(auto c : abc){
        cout << c << endl;
    }

    //converts every character to uppercase
    for(auto &c : abc){ //for every char in s (note: c is a reference)
        c = toupper(c);
    }
    cout << abc << endl;

    //using decltype since s.size() gives a weird type
    string s = "momther vxcvxb";
    
    for (decltype(s.size()) index = 0; index != s.size() && !isspace(s[index]); index++){
        s[index] = toupper(s[index]);
    }
    
    cout << s << endl;


    //count_if
    string gay = "gay gay gay gay gay gay gay gay";
    int count = count_if(gay.begin(), gay.end(), is_y); //<algorithm> needed to run this function
    cout << count << endl;

    //substring stuff
    string my_string = "This is a sample string";
    
    string sub1 = my_string.substr(0, 4); // 0 to 4 (elemnts)
    string sub3 = my_string.substr(5, 2); //Extract substring starting at index 5 with length 2 ("is")


    //iterating over each character in a string
    string x = "DOG";
    for(const char& c : x){
        cout << c << endl; 
    }


    //adding elements to a string - APPEND()
    string str1("Hello World! ");
    string str2("GeeksforGeeks");

    // Append the str2 in to str1
    str1.append(str2);

    cout << str1 << endl;

    //mixing data types 
    // + method, one element must be of string type
    string name = "Bob";
    int version = 3;
    string msadsd = name + to_string(version);

    //stream method, must have std::sstream
    stringstream ss;
    string name = "Alice";
    int age = 30;

    ss << "Name: " << name << ", Age: " << age;
    std::string result_str = ss.str();

    //MISC
    std::string::npos; //means not found or no position. Used in functions like find(), rfind(), find_first_of() when condition is asking for not found.
    return 0;
}