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