#include <stdlib.h>

//returns the amount of character of string excluding null
size_t my_strlen(const char* s) {
    size_t n = 0;
    while (s[n] != '\0') n++;
    return n;
}

//compares two strings and returns zero if equal, and if not returns the difference
int my_strcmp(const char* a, const char* b) {
    while (*a && (*a == *b)) {
        a++;
        b++;
    }

    return (unsigned char)(*a) - (unsigned char)(*b);
}

int main() {

    return 0;
}
