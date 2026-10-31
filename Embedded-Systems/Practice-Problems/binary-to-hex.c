#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* toHex(int num) {
    char* res = (char*)malloc(20 * sizeof(char));
    strcpy(res, "");

    char hex_value[] = "0123456789abcdef";
    int arr[8];
    int i;
    for(i = 0; i < 8; i++){
        arr[i] = num & 15;
        num = num >> 4;
    }


    i = 7;
    int started = 0;
    int len = strlen(res);
    while (i >= 0){
        if (arr[i] != 0 || started) {
        res[len] = hex_value[arr[i]];
        len++;
        started=1;
        }

        i--;
    }

    if (started == 0) {
        res[len] = '0';
        len++;
    }
    
    res[len] = '\0';
    return res; 
}


int main() {
    printf("%b\n", -4);
    // Test Case 1: A simple positive number
    int num1 = 26; // Hex: 1a
    char* expected1 = "1a";
    printf("Test 1: Input = %d, Expected = %s\n", num1, expected1);
    char* result1 = toHex(num1);

    // Test Case 2: Zero
    int num2 = 0; // Hex: 0
    char* expected2 = "0";
    printf("Test 2: Input = %d, Expected = %s\n", num2, expected2);
    char* result2 = toHex(num2);

    // Test Case 3: A negative number (two's complement)
    int num3 = -1; // Hex: ffffffff
    char* expected3 = "ffffffff";
    printf("Test 3: Input = %d, Expected = %s\n", num3, expected3);
    char* result3 = toHex(num3);

    // Test Case 4: A larger number
    int num4 = 255; // Hex: ff
    char* expected4 = "ff";
    printf("Test 4: Input = %d, Expected = %s\n", num4, expected4);
    char* result4 = toHex(num4);

    return 0;
}