#include <stdio.h>
//UNCOMMENT THE BELOW "defines" to see the diference and make sure to ctrl + s 
// #define PLATFORM_WINDOWS 1
// #define PLATFORM_LINUX 1 

int main() {
    #ifdef PLATFORM_WINDOWS
        printf("Running on Windows.\n");
        // Windows-specific code here
    #elif defined(PLATFORM_LINUX)
        printf("Running on Linux.\n");
        // Linux-specific code here
    #else
        printf("Running on an unknown platform.\n");
    #endif

    #ifdef DEBUG_MODE
        printf("Debug mode is enabled.\n");
        // Debugging code here
    #endif

    return 0;
}
// The code checks if PLATFORM_WINDOWS is defined. If it is, the Windows-specific message is printed.
// If PLATFORM_WINDOWS is not defined, it checks if PLATFORM_LINUX is defined.
// If neither is defined, the "unknown platform" message is printed.
// The debugging code within the #ifdef DEBUG_MODE block will only be included if the DEBUG_MODE macro is defined (e.g., via a compiler flag).