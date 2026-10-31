// Given two binary strings a and b, return their sum as a binary string.
// Constraints: 1 <= a.length, b.length <= 10^4. a and b consist only of '0' or '1' characters. Each string does not contain leading zeros except for the zero itself.
#include <inttypes.h>
#include <stdio.h>
#include <string.h>
char* addBinary(char* a, char* b) {\
    size_t a_sz = strlen(a);
    size_t b_sz = strlen(b);

    size_t max_size = a_sz > b_sz ? a_sz : b_sz;

    //worst case scenario buffer
    char* res = (char*)malloc((max_size * sizeof(char))+2);

    uint16_t ptr_a = 0;
    uint16_t ptr_b = 0;
    uint16_t ptr_res = len(res);
    uint16_t carry_over = 0;

    /*
    b = 11111
    a =  1101
    
    */
    if (b > a){
        while (a < a_sz){
            if ((a[ptr_a] == 0 && b[ptr_b] == 1) || (a[ptr_a] == 1 && b[ptr_b] == 0) && carry_over==0){
                res[ptr_res] = 1; 
                ptr_res++; ptr_a++; ptr_b; 
                continue;
            } else if (a[ptr_a] == 1 && b[ptr_b] == 1 && carry_over==0) {
                carry_over++;
                res[ptr_res] = 0; 
                ptr_a++; ptr_b++; ptr_res;
                continue;
                //if 0 and 1 but carry over is >0
            } else if ((a[ptr_a] == 0 && b[ptr_b] == 1) || (a[ptr_a] == 1 && b[ptr_b] == 0)&& carry_over>0){
                res[ptr_res] = 0;
                carry_over--;
                carry_over++; 
                ptr_res++; ptr_a++; ptr_b; 
                continue;
            }  else if (a[ptr_a] == 1 && b[ptr_b] == 1 && carry_over>0) {
                res[ptr_res] = 1; 
                carry_over--;
                carry_over++;
                ptr_a++; ptr_b++; ptr_res;
                continue;
                //if 0 and 1 but carry over is >0
            }
        }

        while (b < b_sz){
            if (carry_over > 0 &&  b[ptr_b] == 1){
                res[ptr_res] = 0; 
                ptr_res++; ptr_b++;
                continue;
            } else if (carry_over > 0 && b[ptr_b] == 0){
                carry_over--;
                res[ptr_res] = 1; 
                ptr_res++; ptr_b++;
                continue;
            }
        }
            
            else
    }else{
        
    }
}

int main(){
    // Test Case 1: Simple addition
    char* a1 = "11";
    char* b1 = "1";
    char* result1 = addBinary(a1, b1);
    printf("Test 1: %s + %s = %s (Expected: 100)\n", a1, b1, result1);
    free(result1);

    // Test Case 2: Different lengths with carry
    char* a2 = "1010";
    char* b2 = "1011";
    char* result2 = addBinary(a2, b2);
    printf("Test 2: %s + %s = %s (Expected: 10101)\n", a2, b2, result2);
    free(result2);

    // Test Case 3: No carry
    char* a3 = "101";
    char* b3 = "10";
    char* result3 = addBinary(a3, b3);
    printf("Test 3: %s + %s = %s (Expected: 111)\n", a3, b3, result3);
    free(result3);

    // Test Case 4: Adding zero
    char* a4 = "1101";
    char* b4 = "0";
    char* result4 = addBinary(a4, b4);
    printf("Test 4: %s + %s = %s (Expected: 1101)\n", a4, b4, result4);
    free(result4);

    return 0;
}