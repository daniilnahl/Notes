int parseCommand(char* line, char* outTokens[], int maxTokens) {
    if (line == NULL ||
    !(*line) || 
    maxTokens <= 0 ||
    *line == '\0') return 0;

    int count = 0;
    char* p = line;
    
    outTokens[count++] = p;
    while (*p && count < maxTokens){
        if (*p == ','){
            *p='\0';
            p++;
            outTokens[count++] = p;
            continue;
        }

        p++;
    }

    return count;
}

/****** 
 * WHAT WAS CORE IDEA?
 The core idea was to first check if the terminal input, 'line', is a valid pointer and is pointing to a valid value and check other parameters to see even if we should begin operations.
 Then create a count and temporary char* variables to track the field elements as wall as not modify the 'line' variable directly. At that point it is guaranteed that the 1st char of 'line' is some
 valid field value thus we assign it into out variable and increment the pointer. Then enter a loop with the conditions of while *p is not equal to null terminator and the out array has capacity for more
 elements. Then within the loop increment the temp char* ptr and check if its pointing at a comma, if yes then replace it with null terminator, increment it and assign a new address into the out array.
 *  ***/

