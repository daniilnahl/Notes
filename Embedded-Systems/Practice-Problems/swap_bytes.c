// Implement byte-order reversal (endian conversion):
// bswap16(x) — swap the two bytes of a 16-bit value
// bswap32(x) — reverse the four bytes of a 32-bit value

//The whole idea is that when bits are shifed outside the scope they are 
//just discarded and due to that by shfiting 8 to left and right we can isolate
//1st and 2nd bytes in the swapped order and then return it.
uint16_t bswap16(uint16_t x) {
    return (uint16_t) ((x << 8) | (x >> 8));
}

//The whole idea around this problem is very similiar but now by shifting bits left or right
//we are not going to be able to discard all the other bytes like in the function above thus we need
//to isolate (better term would be masked) for that specific field. Shifting operations still happen
// but an AND operation is added that the bits shifted into that specific positions are the only
//ones preserved.
uint32_t bswap32(uint32_t x) {
    return (uint32_t)((x >> 24) & 0x000000FFu) | 
            (uint32_t)((x << 24) & 0xFF000000u) |
            (uint32_t)((x << 8) & 0x00FF0000u) |
            (uint32_t)((x >> 8) & 0x0000FF00u);   
    // Your code here
}

