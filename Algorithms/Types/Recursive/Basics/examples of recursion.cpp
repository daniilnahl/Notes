#include <iostream>
using namespace std;

//basic
void countdown(int i){
    cout << i << endl;
    if (i <= 0){ //base case
        return;
    } else{//recursive case 
        countdown(i-1);
    }
}

//call stack with recursion
int fact(int x){
    if (x==1){
        return 1;
    }
    else{
        return x * fact(x-1);
    }
}
int main() {

    countdown(10);
    cout << fact(3) << endl;

    return 0;
}