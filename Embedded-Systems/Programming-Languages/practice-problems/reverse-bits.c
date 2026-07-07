#include <stdio.h>

int reverseBits(int n) {
    //MUST USE 'Bit Twiddling'
    //first swap odd and even bits
    //1st half shifts odd and second shifts even bits
    n = ((n >> 1) & 0x55555555) | ((n << 1) & 0x55555555); //basically moves odds to evens and vice versa
    //repeat the process for pairs
    n = ((n >> 2) & 0x33333333) | ((n << 2) & 0x33333333); //now does it with groups of 2s
    //reapet for groups of 4 
    n = ((n >> 4) & 0x0F0F0F0F) | ((n << 4) & 0x0F0F0F0F); //groups of 4s
    //swap bytes
    n = ((n >> 8) & 0x00FF00FF) | ((n << 8) & 0x00FF00FF); //8s
    //swap 16s
    n = (n >> 16) | (n << 16); //16s

    printf("%b\n", n);

    return n;
}

int main() {
    reverseBits(1);
    reverseBits(10);
    reverseBits(5);
    return 0;
}