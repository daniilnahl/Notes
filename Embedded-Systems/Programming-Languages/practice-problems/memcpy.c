#include <inttypes.h>
#include <stdlib.h>

void* my_memcpy(void* dest, const void* src, size_t n) {
    if (n == 0) return dest;
    
    unsigned char* d =  (unsigned char*)(dest);
    unsigned char* source = (unsigned char*)(src);

    for (size_t i = 0; i < n; i++) d[i] = source[i];

    return dest;
}
/****** 
 * WHAT WAS CORE IDEA?
 The core idea is that we need to copy exactly N bytes from one place to another.
 To achieve that we need to ensure that each byte is accessed by itself. Thus, we need to cast both pointers to a type
 that has a size and alignment of 1 byte, which will prevent any issues where multiple bytes are accessed at once. For example we access src[0] and src is uin32t 
 so we access 4 bytes at once instead of a single byte which both breaks the requirements of the problem and in case of N being an odd number prevents us from achieving the task.

 *  What concept was used? Memory alignment and byte access.

 * WHAT TIME COMPLEXITY? Time complexity is O (n)
 * 
 * WHAT SPACE COMPLEXITY? Space complexity is O (1)
 * 
 *  ***/

