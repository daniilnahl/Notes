#include <stdio.h>   
#include <stdlib.h>     /* strtoul 1st: C-string containing the num 2nd: tracks where strtoul stopped converting 3rd: numerical base  **/

int main() {
    //STRING TO UNSIGNED
    char buffer [256] = "123asd";
    unsigned long ul;
    
    ul = strtoul (buffer, NULL, 0);
    printf ("Num is: %lu. Its double: %lu\n",ul,ul*2);
    return 0;
}