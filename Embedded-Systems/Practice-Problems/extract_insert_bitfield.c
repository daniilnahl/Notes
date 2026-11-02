// Implement two operations on an unsigned 32-bit word. Bit positions are 0-based (LSB = bit 0).
// extract(num, pos, width) — return the contiguous bitfield of width bits starting at pos as an integer in [0, 2^width).
// insert(num, val, pos, width) — write the low width bits of val into num at position pos (all other bits of num unchanged) and return the new word.


unsigned extract(unsigned num, unsigned pos, unsigned width) {
    uint32_t field = (width == 32) ? 0xFFFFFFFFu : ((1u << width) - 1u);
    uint32_t mask = field << pos;
    return (num & mask) >> pos;
}

unsigned insert(unsigned num, unsigned val, unsigned pos, unsigned width) {
    uint32_t field = (width == 32) ? 0xFFFFFFFFu : ((1u << width) - 1u);
    //mask is full of 1s
    uint32_t mask = field << pos;

    //by inverting mask now its all 0s thus it clears out all the bits at the specific bitfield
    //which allows to paste in the 'val' field, completing the insert operation
    return (num & ~mask) | ((val & field) << pos);
}


/****** 
 * WHAT WAS CORE IDEA?
 The core idea in both solutions is to first determine what is the width of the bit-field we are working with
 then from there move that bitfield into the starting position determined by the given 'pos' parameter.
 In case of extraction the given reg is ANDed with the mask (which captures the bit within that exact bit field) and the result 
 of that is shifted to the left by same 'pos' parameter we shifted the field to the right when created the mask.
 
 In Case of insertion the we invert the mask and AND it with the given register which ensures all the bits within that bitfield are cleared
 from there we OR the result of that with the val parameter that is ANDed with the field parameter to ensure we insert specifically width param. defined
 bitfield within the register then we shift to the left by 'pos' parameter and set the insertion value into the given bitfield at specified pos.
 * WHAT PATTERN/DSA DID THIS USE?
 * The DSA/PATTERN I used bit manipulation.
 *  *  
 * WHAT TIME COMPLEXITY? O (1)
 * 
 * WHAT SPACE COMPLEXITY? O (1)
 *  * 
 *  ***/
