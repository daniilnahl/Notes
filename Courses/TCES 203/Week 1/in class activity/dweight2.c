/***
 * Author: Daniil Nahliuk
 * Task:
 *  Create dweight2.c that prompts for height, length, and width (all int), computes volume = h*l*w;
 *  then computes dimensional weight using:
 *  `
 * #define INCHES_PER_POUND 166
 * weight = (volume + INCHES_PER_POUND - 1) / INCHES_PER_POUND;
 *  `
 * 
 * Finally print volume and dimensional weight on separate lines.
 * Constraints: Prompts must not end with \n; use scanf("%d", &height); pattern; use the macro name in the formula.
 */
#define INCHES_PER_POUND 166
#include <stdio.h>

int main(){
    int h, l, w;
    printf("Enter height: ");
    scanf("%d", &h);
    printf("Enter length: ");
    scanf("%d", &l);
    printf("Enter width: ");
    scanf("%d", &w);

    int volume = h * l * w;
    int weight = (volume + INCHES_PER_POUND - 1) / INCHES_PER_POUND;
    printf("Volume is %d%c", volume,10);
    printf("Weight is %d",weight);
}
