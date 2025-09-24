/***
 * Author: Daniil Nahliuk:
 * Task:  Use macro definitions for named constants and format floating-point output.
* Create celsius.c that reads a Fahrenheit value and prints the Celsius equivalent to one decimal place. Use:
* `#define FREEZING_PT 32.0f
*  #define SCALE_FACTOR (5.0f / 9.0f)`
*Constraints: Use float variables; scanf("%f", &fahrenheit);; print with printf("Celsius equivalent: %.1f\n", celsius);.
*/
#include <stdio.h>
#define SCALE_FACTOR (5.0f / 9.0f)
#define FREEZING_PT 32.0f

int main() {
    float f, c;

    printf("Enter a Fahrenheit value: ");
    scanf("%f", &f);
    c = (f - FREEZING_PT) * SCALE_FACTOR;
    printf("Celsius equivalent: %.1f\n", c);
    return 0;
}