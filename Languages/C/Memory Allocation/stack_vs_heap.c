#include <stdio.h>
#include <stdlib.h>

int global_var = 10; // Stored in the data segment (not stack or heap)

void another_function() {
    int local_var_another = 30; // Stored on the stack because its inside a function
    printf("Inside another_function: local_var_another = %d\n", local_var_another);
}

void some_function() {
    int local_var = 20; // Stored on the stack becuase inside a function
    int *heap_var = (int*)malloc(sizeof(int)); // Allocated on the heap because manually allocated
    if (heap_var == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    *heap_var = 40;
    printf("Inside some_function: local_var = %d, heap_var = %d (at address %p)\n", local_var, *heap_var, heap_var);
    another_function();
    free(heap_var); // Important to free heap memory
}

int main() {
    int main_local_var = 10; // Stored on the stack becasue inside a function
    printf("Inside main: main_local_var = %d, global_var = %d\n", main_local_var, global_var);
    some_function();
    return 0;
}