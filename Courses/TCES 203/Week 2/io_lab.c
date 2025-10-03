/***
 * Author: Daniil Nahliuk
 * Coding Activity 2 (C)
 */
#include <stdio.h>

int main(){    
    printf("TWO LINE HEADING\n\"Item\"\t\t\\\t\"Value\"\t\t\\\t\"Notes\"\n\n");
    int integer = 12345678;
    float not_integer = 1.2345678123456789;
    printf("Shortened Float using g specifier: %g\n",not_integer);
    printf("Float(with precision): %.15f\n",not_integer);
    printf("Float(with width): %3.f\n",not_integer);
    printf("Float(without specified width and precision): %f\n",not_integer);
    printf("Int: %d\n",integer);

    printf("--------------------------------\n\n");

    int m1, d1, m2, d2;
    printf("Enter date mm/dd - ");
    int res1 = scanf("%d/%d",&m1,&d1);
    if(res1 != 2){
        printf("Input characters are incorrect\n\n");
        return 1;
    }else{
        printf("%d/%d\n",m1,d1);   
    }

    printf("Enter date mm:dd - ");
    int res2 = scanf("%d:%d",&m2,&d2);
    if(res2 != 2){
        printf("Input characters are incorrect\n\n");
        return 1;
    }else{
        printf("%d:%d\n",m2,d2);   
    }

    printf("--------------------------------\n\n");

    int num1, num2, den1, den2, res_num, res_den;

    printf("Enter first fraction: ");
    scanf("%d/%d", &num1, &den1);
    printf("Enter second fraction: ");
    scanf("%d/%d", &num2, &den2);
    printf("Entry\t\tNumerator\t\tDenominator\t\t\n");
    printf("First\t\t%4d\t\t\t%4d\n", num1, den1);
    printf("Second\t\t%4d\t\t\t%4d\n", num2, den2);
    res_num = num1 * den2 + num2 *den1;
    res_den = den1 * den2;
    printf("Sum\t\t%5d\t\t\t%5d\n", res_num, res_den);


    return 0;
}