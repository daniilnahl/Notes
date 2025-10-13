#include <stdio.h>

int main(){
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    if (num == 0) printf("The number is zero.\n");
    else if( num < 0) printf("The number is negative.\n");
    else printf("Number is positive.\n");
    
    if (num % 2 == 0) printf("The number is even.");
    else printf("The number is odd.");

    return 0;
}