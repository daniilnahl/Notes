/***Create a function with two arguments that will return an array of the first n multiples of x.
Assume both the given number and the number of times to count will be positive numbers greater than 0.
Return the results as an array or list.
x = 1, n = 10 --> [1,2,3,4,5,6,7,8,9,10]
x = 2, n = 5  --> [2,4,6,8,10]
****/

void count_by(unsigned x, unsigned n, unsigned result[n]) {
    for(unsigned i = 0; i < n; i++){
      result[i] = x * (i+1);
    }
  }
int main() {
  int n = 10;
  //TO dynamically allocate memory in C for an array set the size times the size of the data type for memory.
  //A specific data type has a set amount of required bytes to hold just one value of its type, thus if you need more than just one element in an array you must do the n * size of the type.
  long long *nums = malloc(n * sizeof(long long)); //dynamically allocating memory. Example.

  //gives the size of an array. NUM OF ELEMENTS / SIZE OF AN ARRAY AT ELEMENT 0. (N / 1) = N;
  int size = sizeof(nums) / sizeof(nums[0]);
  return 0;
}
  
/****
 * Tip: Inside a function that receives an array as an argument, the parameter is treated as a pointer to the first element. 
 * Therefore, operations like sizeof(arr) inside the function will return the size of the pointer, not the size of the original array. 
 * This is why you usually need to pass the size explicitly.
 * 
 */