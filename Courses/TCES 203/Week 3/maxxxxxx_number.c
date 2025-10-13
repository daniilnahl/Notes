#include <stdio.h>

int main(){
    int x, y, z;
    printf("enter x,y,z: ");
    scanf("%d,%d,%d", &x, &y, &z);
    printf("Part A\n\n");
    if (x > y){
        if (y > z) printf("x(%d) is the largest number.\n",x);
        else if (z > x)  printf("z(%d) is the largest number.\n",z);
        else if (z == x) printf("x(%d) and z(%d) are equally the greatest numbers.\n",x,z);

    }else{//y > x
        if (x > z)  printf("y(%d) is the largest number.\n",y);
        else if (z > y)  printf("z(%d) is the largest number.\n",z);
        else if (z == y) printf("y(%d) and z(%d) are equally the greatest numbers.\n",y,z);
    }  

    printf("\n\nPart B\n\n");
    printf("The largest num is %d", (y > x ? (y > z ? y : z) : ((x > z ? x : z))));

    return 0;
}