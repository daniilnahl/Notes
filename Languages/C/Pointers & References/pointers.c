
int char_to_int(uint8_t *character) { //parameter expects a pointer to a specific data type
    return (int) *character - '0'; //*characterr derefences the pointer and gets the value at the adress the pointer is pointing to
    //inside this function charcter is just the adress.
}

int add(int a, int b) {
    return a + b;
}


int main() {
    int age = 30; // Declare an integer variable
    int *agePtr; // Declare a pointer to an integer

    agePtr = &age; // Initialize the pointer with the memory address of 'age'

    printf("Value of age: %d\n", age);
    printf("Memory address of age: %p\n", (void *)&age); // Use %p to print memory addresses
    printf("Value of agePtr (memory address of age): %p\n", (void *)agePtr);

    //pointer arithmetic
    int numbers[] = {10, 20, 30, 40, 50};
    int *ptr = numbers; // 'numbers' decays to a pointer to the first element

    printf("First element: %d\n", *ptr);

    ptr++; // Increment the pointer to point to the next integer
    printf("Second element: %d\n", *ptr);

    ptr += 2; // Increment the pointer by two integer positions
    printf("Fourth element: %d\n", *ptr);


    //pointer to functions
    // Declare a pointer to a function that takes two integers and returns an integer
    int (*functionVariablePointer)(int, int);

    // Assign the address of the 'add' function to the pointer
    functionVariablePointer = add; // or functionVariablePointer = &add;

    // Call the function through the pointer
    int result = (*functionVariablePointer)(5, 3); // or result = functionVariablePointer(5, 3);

    printf("Result of addition: %d\n", result);
    return 0;

    //FOR ARRAYS THERE ARE TWO MAIN TYPES OF POINTER DEREFERENCING: indexing and pointer dereference.
    printf("First element using array indexing: %d\n", numbers[0]);
    printf("First element using pointer dereference: %d\n", *ptr);

    printf("Second element using array indexing: %d\n", numbers[1]);
    printf("Second element using pointer arithmetic: %d\n", *(ptr + 1));

    printf("Third element using array indexing: %d\n", numbers[2]);
    printf("Third element using pointer arithmetic: %d\n", *(ptr + 2));   
}