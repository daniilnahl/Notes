#include <bits/stdc++.h> //collections of headers like iostream, vector, map and more. 
 using namespace std;

// Function to split the array into two parts around a pivot
 int partition(vector<int>& arr, int low, int high){
    // The pivot is the last element in the array
    int pivot = arr[high];

    // This will keep track of where the smaller elements should go
    int i = low - 1;

    // Loop through the array to compare each element with the pivot
    for (int j = low; j <= high - 1; j++){
        if (arr[j] < pivot){ // If the current element is smaller than the pivot
            i++; // Move the "smaller elements pointer" forward
            swap(arr[i], arr[j]); // Swap the smaller element to its correct position
        }
    }
    // Put the pivot in its correct position so everything smaller is on the left
    // and everything larger is on the right
    swap(arr[i + 1], arr[high]);

    // Return the index of the pivot
    return i + 1; 
 }

 //quicksort function
 void quick_sort(vector<int>& arr, int low, int high){
    if (low < high) {// Stop when the part of the array is empty or has one element
        // Find the pivot's correct position
        int pi = partition(arr, low, high);
        //!!calling quicksort
        quick_sort(arr, low, pi - 1); //sorts smaller elemenets. p - 1 so it doesnt change the position of the pivot.
        quick_sort(arr, pi + 1, high); //sorts larger elements. p + 1 so it doesnt change the position of the pivot.
    }
 }

 int main() {
    vector<int> arr = {10, 7, 8, 4, 2, 6};
    int n = arr.size();
    quick_sort(arr, 0, n - 1);

    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    return 0;
 }