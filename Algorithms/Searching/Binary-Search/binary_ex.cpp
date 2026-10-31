#include <iostream>
#include <iterator>

using namespace std;

int binary_search(int x[10], int target){//cant pass an array as a parameter into a function in c++
    int left = 0;
    int right = 9;

    while (left <= right){
        int mid = (left + right) / 2;

        if (x[mid] == target){
            return mid - 1;
        }

        else if (x[mid] < target){
            left = mid + 1;
        }
        
        else
        {
            right = mid - 1;
        }
    
    }

    return -1;
}
int main(){
    int arr[10] = {0,1,2,3,4,5,6,7,8,9};
    cout << "at what index is 4 at should be(3): " << binary_search(arr, 4) << endl;
    return 0;
}