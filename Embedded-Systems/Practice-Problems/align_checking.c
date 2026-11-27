// Implement ALIGN_UP / Check Alignment — C starter (adapt types/structs as needed)
/*
Examples:
alignUp(5, 4)   → 8
alignUp(8, 4)   → 8
alignUp(14, 8) -> 16
alignUp(19, 16) -> 32
*/
size_t alignUp(size_t value, size_t align) {
    if (value == 0) return 0U; //edge case
    if (value <= align) return align;
    else{ //greater than align value
        size_t offsetFits = value / align;
        size_t offsetRem = value % align;

        if (offsetRem == 0U) return offsetFits * align;
        else return (offsetFits+1) * align;
    }
}

/****** 
 * WHAT WAS CORE IDEA?
The core idea was to just retun align if the value is less than it and to return 'how many aligns' (+1 or +0) can fit within value times the align value.
 *  ***/


bool isAligned(size_t value, size_t align) {
    return (value % align == 0U) ? true : false;
}


