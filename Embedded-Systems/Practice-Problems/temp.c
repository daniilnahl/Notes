// Implement two classic C string helpers (no libc):

// my_strlen(const char* s) — return the number of characters before the terminating '\0'.
// my_strcmp(const char* a, const char* b) — return < 0, 0, or > 0 like libc strcmp (lexicographic by unsigned char values).


size_t my_strlen(const char* s) {
    size_t count = 0;
    while(s[count] != '\0') count++;

    return count;
}

int my_strcmp(const char* a, const char* b) {
    while (*b == (*a == *b)){
        a++;
        b++;
    }

    return (unsigned char)(*a) - (unsigned char)(*b); 
}