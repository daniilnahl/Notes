#include <stdio.h>    
#include <string.h>

int main(){

    //OUTPUT
    printf("This is C\n");

    int test_int = 5;
    printf("Num is %d", test_int, "\n"); //need %d as format specifier for int

    float test_f = 0.5;
    double test_d = 0.56;
    printf("num is %f", test_f, "\n");// need %f for format specifier
    printf("num is %0.01f", test_f, "\n");//rounds to 0.0. TO round to 0.00 do %0.02f, etc.
    printf("num is %lf", test_f, "\n");// need %lf for format specifier (lf - long float)

    char c = 'a';
    printf("char is %c", c, "\n"); // need %c for format specifier


    //INPUT
    int test_int2;
    printf("input int: ");
    scanf("%d", &test_int2);  //&(var) gets the address of the variable and stores the input there 
    printf("Number = %d",test_int2, "\n");

    //scanf("(type)" // Type depends on type of variable so, %d %f %lf %c

    //ASCII
    char chr;
    printf("Enter a character: ");
    scanf("%c", &chr);     

    // When %c is used, a character is displayed
    printf("You entered %c.\n",chr);  

    // When %d is used, ASCII value is displayed
    printf("ASCII value is %d.", chr);  

    /****
     * HOW DOES THE BELOW CODE WORK?
     * %(width)(specifier) - pads the outpud with spaces to reach the stated width.
     * %0(width)(specifier) - pads the outpud with leading zeroes to reach the stated width.
     */
    char* buffer[4];
    int number = 4;
    sprintf(buffer, "%02d", number); 
    // Formats an integer number into a string buffer, 
    // padding with a LEADING ZERO if it's less than 10, doesnt do it if its more than 10.
    // ensuring a minimum width of two characters.
    return 0;

    
}