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

#define BUFFER_SIZE 64

typedef struct CircularBuffer {
    uint8_t data[BUFFER_SIZE];
    uint8_t head; //index of head
    uint8_t tail; //index of tail
    uint8_t count;
} CircularBuffer;

// Initialize buffer
void cb_init(CircularBuffer *cb){
    if (cb == NULL) return;

    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
}

// Insert a byte
bool cb_push(CircularBuffer *cb, uint8_t value){
    if (cb == NULL || cb->count == BUFFER_SIZE) return false;

    cb->data[cb->tail] = value;
    cb->tail = (cb->tail + 1U) & BUFFER_SIZE;
    cb->count++;

    return true;
}

// Remove the oldest byte
bool cb_pop(CircularBuffer *cb, uint8_t *out){
    if (cb == NULL || out == NULL || cb->count == 0) return false;
    *out = cb->data[cb->tail];
    cb->head = (cb->head + 1U) & BUFFER_SIZE;
    cb->count--;

    return true;
}