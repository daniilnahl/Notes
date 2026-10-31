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



#define BUFFER_SIZE 64

typedef struct CircularBuffer CircularBuffer;

// Initialize buffer
void cb_init(CircularBuffer *cb);

// Insert a byte
bool cb_push(CircularBuffer *cb, uint8_t value);

// Remove the oldest byte
bool cb_pop(CircularBuffer *cb, uint8_t *out);