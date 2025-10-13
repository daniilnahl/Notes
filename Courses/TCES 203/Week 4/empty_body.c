#include <stdio.h>

int main(){
    unsigned int n;
    printf("Enter a non-negative integer: ");
    scanf("%u", &n);
    int digits = 0;
    do{
        n /= 10;
        digits++;
    } while (n > 0);

    printf("The number has %d digit(s).\n",digits);
    return 0;
}