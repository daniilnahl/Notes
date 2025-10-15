#include <stdio.h>

int main(){
    int n;
    printf("Enter an integer >1: ");
    scanf("%d", &n);
    for (int i = n-1; i > 0; i--){
        if (n % i == 0){
            printf("%d is divisible by %d",n,i);
            break;
        }
    }
}