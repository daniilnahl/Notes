
#include <stdbool.h>

// x is the register
// bit is the location of the bit we will be operating on
unsigned setBit(unsigned x, unsigned bit) {
    x |= (1u << bit);
    return x;

}

unsigned clearBit(unsigned x, unsigned bit) {
    x &= ~(1u << bit);
    return x;
}

unsigned toggleBit(unsigned x, unsigned bit) {
    x ^= (1u << bit);
    return x;
}

bool testBit(unsigned x, unsigned bit) {
    return x & (1u << bit);
}

