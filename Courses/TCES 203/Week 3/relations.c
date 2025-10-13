#include <stdio.h>

int main(){
    int a, b, c, res;
    printf("print three integers: ");
    scanf("%d %d %d",&a, &b, &c);
    res = a < b;
    printf("a < b: %d\n", res);
    res = a <= c;
    printf("a <= c: %d\n", res);
    res = a == c;
    printf("a == c: %d\n", res);
    res = a < b && b < c;
    printf("result of a < b && b < c is %d\n", res);
    res = a < b || b > c;
    printf("result of  a < b || b > c %d\n", res);
    res = !(a==b);
    printf("result of !(a==b) is %d\n", res);

    return 0;
}