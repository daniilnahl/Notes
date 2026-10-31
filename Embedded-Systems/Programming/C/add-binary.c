#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* addBinary(const char* a, const char* b) {
    if (!a || !b) return NULL; 
    size_t a_size = strlen(a);
    size_t b_size = strlen(b);
    size_t max_size = (a_size > b_size) ? a_size : b_size;

    char* res = (char*)malloc(max_size+2);
    if (!res) return NULL; //malloc fail
    int i = (int)a_size - 1;
    int j = (int)b_size - 1;
    int k = 0;
    int carry_out = 0;
    int sum = 0;

    while (i >= 0 || j >= 0 || carry_out){
        sum = carry_out;

        if (i >= 0) sum += a[i--] - '0'; //basically casting the char values to their values and all the numbers are counter from some # which is 0 (lets say n) thus '1' is just n+1 so this sub will result in 1
        if (j >= 0) sum += b[j--] - '0';

        res[k++] = (char)((sum & 1) + '0');
        carry_out = sum >> 1;
    }

    res[k] = '\0';

    for (int left = 0, right = k - 1; left < right; left++, right--){
        char temp = res[left];
        res[left]=res[right];
        res[right] = temp;
    }

    return res;
}

/****** 
 * WHAT WAS CORE IDEA?
 The core idea was to start with allocating heap memory for the resulting string ensuring that both '\0' and an extra 1 will fit within it.
 Then starting with the LSB bit of each binary string and looping a while loop under the conditions of that all pointers are greater than or equal to 0 and that carry_out bit has a value (of 1).
 Within that loop assign sum value the carry bit from the previous summation and add up the values of each of the strings by casting the char values into their ASCII integer representation and subing by '0'.
 This works because each numeric value in ASCII begins from '0' + n. Eg '0' is x and '1' is x + 1. Which perfectly works for the binary summation.
 Then to determine the value of the current resulting bit AND sum againt a 1 and then add '0' to cast that back to a char. 
 To ensure the carry bit is properly tracked shift sum by 1 to the right which ensure thats if sum is 2 (10) the carry bit become 1 (01) for the next iteration.
 Ensure to add null terminator after the while loop and proceed with reversing the result string to put the LSB (which starts at res[0]) into its place at the end of the string.

 * WHAT TIME COMPLEXITY? time complexity is O (max(n,m)) for the longest string
 * 
 * WHAT SPACE COMPLEXITY? Space complexity is O (max(n,m) + 2) which is just O(max(n,m)) for the created string based of the longest string
 * 
 *  ***/

