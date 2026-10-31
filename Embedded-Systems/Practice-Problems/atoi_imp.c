// Implement my_atoi — convert a C string to a 32-bit signed integer 
//(LeetCode-style / embedded parsing).

// Rules:
// 1. Skip leading ASCII spaces (' ' only — tabs/newlines optional bonus).
// 2. Optional + or -.
// 3. Read consecutive digits; stop at first non-digit.
// 4. If the value overflows 32-bit signed range, clamp to 
// INT_MAX (2147483647) or INT_MIN (-2147483648).

int myAtoi(char* s) {
    int i=0, sign=1;
    long long int res = 0;
    
    //skip whitespace
    while (s[i] != '\0' && s[i] == ' ') i++;
    //handle signs
    if (s[i] != '\0' && (s[i] == '+' || s[i] == '-')){
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }

    //process digits
    while(s[i] != '\0' && (s[i] <= '9' && s[i] >= '0')){
        res = res * 10 + (s[i] - '0');
        if (res * sign > INT_MAX) return INT_MAX;
        if(res * sign < INT_MIN) return INT_MIN;
        i++;
    }

    return (int)(res * sign);
}
