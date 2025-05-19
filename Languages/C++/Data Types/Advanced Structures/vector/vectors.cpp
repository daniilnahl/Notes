#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//function that only sorts odd values inside a vector
vector<int> sort_array(vector<int> array){
        vector<int> odds;
        copy_if(array.begin(), array.end(), std::back_inserter(odds), [] (int x) {return x % 2;});
        sort(odds.begin(), odds.end());
        for (int i = 0, j = 0; i < array.size(); i++) if (array[i] % 2) array[i] = odds[j++];
        return array;
}

int main() {
    vector<int> ivec = {1, 2, 3};
    vector<int> multi(10, -1); //vectors consistst of 10 elemetns of -1
    // vector<string> ivec1(ivec); error
  
    ivec.push_back(123);
    
    // for(decltype(ivec.size()) i = 0; i < ivec.size(); i++){
    //     cout << ivec[i] << endl;
    // }

    //using sort()
    vector<int> expected = { 15, 8, 3, 1, 16, 9, 12, 3};
    //ascending
    sort(expected.begin(), expected.end());

    for (int i = 0, s = expected.size(); i < s; i++){
        cout << expected[i] << " ";
    }
    cout << endl;
    //descending
    sort(expected.begin(), expected.end(), greater<int>()); 
    //greater<int>() is a comparator function, that determines the sorting order. For descending order, 
    //the comparator ensures that larger elements come before smaller elements.
    for (int i = 0, s = expected.size(); i < s; i++){
        cout << expected[i] << " ";
    }
    cout << endl;

    //sorting but not from start to finish
    sort(expected.begin() + 3, expected.end());

    for (int i = 0, s = expected.size(); i < s; i++){
        cout << expected[i] << " ";
    }
    cout << endl << "Before sorting odd values: ";
    
    //sort array function showcase
    vector<int> test = { 15, 8, 3, 1, 16, 9, 12, 3};
    for (int i = 0, s = test.size(); i < s; i++){
        cout << test[i] << " ";
    }

    cout << endl << "After sorting odd values: ";

    vector<int> results;  
    results = sort_array(test);

    for (int i = 0, s = results.size(); i < s; i++){
        cout << results[i] << " ";
    }

    //sorting vector of strings
    vector<string> abcdsa = {"b","c", "a", "22","104"};
    sort(abcdsa.begin(), abcdsa.end());
    for (int i = 0, s = abcdsa.size(); i < s; i++){
        cout << abcdsa[i] << " ";
    }
    return 0;

}

