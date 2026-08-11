int swapOddEvenBits(int x) {
    //right side shifts the odds into even places and saves it
    //left side  preserves the evens and then shifts thems into odds
    //the bits are correctly shifted such that neither even or odds are ever shifted into the 'abyss'
    return ((x & 0xAAAAAAAA) >> 1) | ((x & 0x55555555) << 1);

}/****** 
 * WHAT WAS CORE IDEA?
 The core idea was to isolate odds bits then move them to the right and then isolate even bits and move them to the left, movements of even and odds in those directions prevents either to be ever shifted into the 'abyss'
 * The DSA/PATTERN I used was bit shifting
 * 
 * Key concepts that I reinforced were bit shifting and I learned a mask to isolate odd bits.
 *  
 * WHAT TIME COMPLEXITY? O(1)
 * 
 * WHAT SPACE COMPLEXITY? O(1)
 *  ***/


