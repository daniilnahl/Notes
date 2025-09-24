/****
 * Author: Daniil Nahliuk
 * Task: Create box.c that declares int height=8, length=12, width=10;
 * computes volume = height * length * width; and prints:
 *  `Dimension 12x10x8
 *   Volume (cubic inches): 960`
*/
#include <stdio.h>

int main(){
    int height = 8, length = 12, width = 10;
    int volume = height * length * width;

    printf("Dimensions %dx%dx%d\n",length, width, height);
    printf("Volume (cubic inches): %d\n", volume);
    return 0;
}