// Implement memmove() — C starter (adapt types/structs as needed)
/*
Implement memmove — copy n bytes from src to dest even if regions overlap, and return dest.
*/

void* my_memmove(void* dest, const void* src, size_t n) {
    unsigned char* d = (unsigned char*)dest;
    const unsigned char* s = (unsigned char*)src;

    if (d == s || n == 0) return dest;
    if (d < s) {
        for (size_t i =0; i < n; i++) d[i] = s[i];
    } else {
        for (size_t i=n; i > 0; i--) d[i-1] = s[i-1];
    }

    return dest;
}

// --- Test your solution ---
// int main() {
//     return 0;
// }
