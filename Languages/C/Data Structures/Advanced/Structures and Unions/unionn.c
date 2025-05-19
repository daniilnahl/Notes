#include <stdio.h>
#include <string.h>
union Data {
    int i;
    float f;
    char str[20];
};

union Value {
    int intValue;
    float floatValue;
    char stringValue[20];
};

enum DataType {
    INT,
    FLOAT
};

struct DataContainer {
    enum DataType type;
    union {
        int intValue;
        float floatValue;
    } value;
};

void printData(struct DataContainer data) {
    if (data.type == INT) {
        printf("Integer: %d\n", data.value.intValue);
    } else if (data.type == FLOAT) {
        printf("Float: %f\n", data.value.floatValue);
    }
}

int main() {
    union Data data1;

    data1.i = 10;
    printf("Integer: %d\n", data1.i);
    
    data1.f = 3.14;
    printf("Float: %f\n", data1.f); // The value of data1.i is now overwritten
    
    strcpy(data1.str, "Hello");
    printf("String: %s\n", data1.str); // The values of data1.i and data1.f are now overwritten

    //value example
    union Value val;

    val.intValue = 15;
    printf("Integer value: %d\n", val.intValue);

    val.floatValue = 3.14159;
    printf("Float value: %f\n", val.floatValue);

    strcpy(val.stringValue, "Hello Union");
    printf("String value: %s\n", val.stringValue);

    //This example demonstrates a tagged union where the type member indicates whether the value union currently holds an integer or a float.
    struct DataContainer intData;
    intData.type = INT;
    intData.value.intValue = 100;
    printData(intData);

    struct DataContainer floatData;
    floatData.type = FLOAT;
    floatData.value.floatValue = 2.71828;
    printData(floatData);
    return 0;
}
// TIPS
// Keep track of the active member: Since only one member of a union is valid at a time, you need a way to know which member currently holds the correct data (often done with a tagged union).
// Be cautious with type punning: While unions can be used for type punning, ensure you understand the implications and potential for undefined behavior.
// Understand memory layout: Remember that all union members share the same memory location. Modifying one member will affect the others.
// Size of a union: The size of a union is determined by the size of its largest member. You can use the sizeof operator to find the size of a union.