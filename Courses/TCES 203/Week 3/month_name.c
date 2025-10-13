#include <stdio.h>

int main(){
    int m;
    printf("Enter month number (1-12): ");
    scanf("%d",&m);
    switch (m)
    {
    case 1: printf("the month is january.\n"); break;
    case 2: printf("the month is february.\n");break;
    case 3:printf("the month is march.\n");break;
    case 4:printf("the month is april.\n");break;
    case 5:printf("the month is may.\n");break;
    case 6:printf("the month is june.\n");break;
    case 7:printf("the month is july.\n");break;
    case 8:printf("the month is august.\n");break;
    case 9:printf("the month is september.\n");break;
    case 10:printf("the month is october.\n");break;
    case 11:printf("the month is november.\n");break;
    case 12:printf("the month is december.\n");break;
    default: printf("Invalid month.\n"); break;
    }

    return 0;
}