#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter the number of integers: ");
    scanf("%d", &n);

    // Dynamically allocate memory for an array of n integers using malloc
    int *arr_malloc = (int*)malloc(n * sizeof(int));
    if (arr_malloc == NULL) {
        printf("Memory allocation failed (malloc).\n");
        return 1;
    }
    printf("Memory allocated using malloc.\n");

    // Dynamically allocate memory for an array of n integers using calloc
    int *arr_calloc = (int*)calloc(n, sizeof(int));
    if (arr_calloc == NULL) {
        printf("Memory allocation failed (calloc).\n");
        free(arr_malloc); // Free previously allocated memory
        return 1;
    }
    printf("Memory allocated using calloc (initialized to zero).\n");

    // Resize the array using realloc
    int new_n = n * 2;
    int *arr_realloc = (int*)realloc(arr_malloc, new_n * sizeof(int));
    if (arr_realloc == NULL) {
        printf("Memory reallocation failed.\n");
        free(arr_calloc);
        free(arr_malloc); // Important: free the original pointer if realloc fails
        return 1;
    }
    printf("Memory reallocated to size %d using realloc.\n", new_n);

    // Use the allocated memory (example: assign values)
    for (int i = 0; i < n; i++) {
        arr_malloc[i] = i + 1;
        arr_calloc[i] = (i + 1) * 10;
    }

    // Free the allocated memory when it's no longer needed
    free(arr_realloc); // Note: arr_realloc now points to the (possibly) new memory block
    free(arr_calloc);

    return 0;
}