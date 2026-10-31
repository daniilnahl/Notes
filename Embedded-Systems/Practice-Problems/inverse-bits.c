#include <stdio.h>
int reverseBits(int n) {
    n ^= 0xFFFFFFFF;
    printf("%b\n", n);

    return 0;
}

int main() {
    reverseBits(7);
    reverseBits(8);
    reverseBits(10);
    return 0;
}