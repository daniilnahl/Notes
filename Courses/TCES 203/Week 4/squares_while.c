#include <stdio.h>

int main(){
    int n, i =1;
    printf("Enter number of entries in table: ");
    scanf("%d", &n);
    while(i <= n){
        printf("\t%d\t%d\n", i, i*i);
        i++;
    }

    return 0;
}