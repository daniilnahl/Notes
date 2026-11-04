/*
Implement a fixed-size circular buffer that stores bytes in FIFO (First In, First Out) order.


INPUT constraints:
1. Buffer capacity: exactly 64 bytes.
2. Values range from 0x00 to 0xFF.
3. Dynamic memory allocation is prohibited.
4. No external libraries for buffer management.
5. Assume operations are called sequentially; concurrent access is not required.


OUTPUT constraints:
1. cb_push() returns true on success and false when full.
2. cb_pop() returns true on success and false when empty.
3. Successful cb_pop() writes the removed value to *out.
4. Failed operations must not modify the buffer's contents or logical state.
5. All 64 slots must be usable.
6. Both operations must have O(1) time complexity.
*/


#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>


typedef struct CircularBuffer{
    uint32_t capacity; 
    uint32_t count;
    uint32_t front;
    uint32_t rear;
    int *arr;
} CircularBuffer;

uint8_t cbInit(CircularBuffer *cb, int cap){
    if (cb == NULL || cap <= 0) return 1U;

    cb->arr = malloc(sizeof(*cb->arr) * cap);
    if (cb->arr == NULL) return 1U;
    else {
        cb->count = 0;
        cb->front = 0;
        cb->rear = 0;
        cb->capacity = cap;    
        return 0U;
        }
    } 

uint8_t cbDeinit(CircularBuffer *cb){
    if (cb == NULL) return 1U;
    free(cb->arr);
    
    return 0U;
}

bool enQueue(CircularBuffer *cb, int value) {
    if (cb == NULL || cb->count == cb->capacity) return false;
    cb->arr[cb->rear] = value;
    cb->rear = (cb->rear + 1U) % cb->capacity;
    cb->count++;

    return true;
}

bool deQueue(CircularBuffer *cb) {
    if (cb == NULL || cb->count == 0U) return false;
    cb->front = (cb->front + 1U) % cb->capacity;
    cb->count--;

    return true;
}

int Front(CircularBuffer *cb, int *error) {
    if (cb == NULL || cb->count == 0){
        *error = 1;
        return -1;
    }

    *error = 0;
    return cb->arr[cb->front];
}

int Rear(CircularBuffer *cb, int *error) {
    if (cb == NULL || cb->count == 0){
        *error = 1;
        return -1;
    }

    *error = 0;
    return cb->arr[(cb->rear + cb->capacity - 1U) % cb->capacity];
}

bool isEmpty(CircularBuffer *cb) {
    if (cb == NULL) return false;
    if (cb->count == 0U) return true;
    return false;
}

bool isFull(CircularBuffer *cb) {
    if (cb == NULL) return false;
    if (cb->count == cb->capacity) return true;
    return false;
}


