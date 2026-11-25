/*
Notes:
1. add checks for failed allocation + parameters being nulls or 0s
2. add mechanism for dealing with double freeing
3. add alignment checks + padding
*/

#include <inttypes.h>
#include <stdlib.h>
#include <stdalign.h>

typedef struct FreeBlock {
    struct FreeBlock* next_block;
} FreeBlock;

typedef struct MemPool {
    size_t block_count;
    size_t block_size;
    size_t block_strides;
    size_t free_blocks;
    struct FreeBlock* free_head;
    uint8_t* pool_start_addr;
    uint8_t* allocation_bitmap;
} MemPool;

MemPool gMemPool;

void poolCreate(size_t capacity, size_t blockSize){
    //if pool is still used and has not been freed, return
    if (gMemPool.pool_start_addr != NULL) return;

    //block size needs to be a minimum the same bytes size as the pointer it needs to hold
    //to inform where the next FreeBlock is
    //AND
    //if capacity is 0, no point in even creating the memory pool
    if (blockSize < sizeof(FreeBlock) || capacity == 0U) return; 
    
    
    //alignment fix: all the blocks' addresses must be aligned according to the system's
    //architecture to prevent misaligned memory accesses (can lead to faults on some systems).
    //alignof(FreeBlock) --> returns the required alignment for the struct
    size_t missingPaddingBytes = 0U;
    if (blockSize % alignof(FreeBlock) != 0U) {
        missingPaddingBytes = alignof(FreeBlock) - (blockSize % alignof(FreeBlock));
    }

    if (blockSize > (SIZE_MAX - missingPaddingBytes)) return; //overflow prevention
    size_t blockStrides = missingPaddingBytes + blockSize;
    
    //the amount of memory is greater than which can be passed into malloc()
    //thus the allocator can't allocate this mem pool.
    if (capacity > (SIZE_MAX / blockStrides)) return;

    uint8_t* temp_addr_pool = malloc(capacity * blockStrides);
    if (temp_addr_pool == NULL) return; //failed to allocate memory

    uint8_t* temp_addr_bitmap = malloc(((capacity/8) + 1) * sizeof(char)); //allocate (capacity/8) amount of bytes for the tracking bitmap
    if (temp_addr_bitmap == NULL) return;

    gMemPool.pool_start_addr = temp_addr_pool;
    gMemPool.allocation_bitmap = temp_addr_bitmap;
    gMemPool.block_count = capacity;
    gMemPool.block_size = blockSize;
    gMemPool.free_blocks = capacity;
    gMemPool.block_strides = blockStrides;

    gMemPool.free_head = (FreeBlock*)gMemPool.pool_start_addr;
    FreeBlock* current = gMemPool.free_head;
    
    //allocate memory to each block
    for (size_t i = 1; i < capacity; i++){
        current->next_block = (FreeBlock*)(((uint8_t*) gMemPool.pool_start_addr) + (gMemPool.block_strides * i));
        current = current->next_block;        
    }
    //prevent undefined behavior
    current->next_block = NULL;
}

//alloc() — return pointer to a free block, or null if none
void* poolAlloc(void){
    //edge cases
    if (gMemPool.free_blocks != 0 && gMemPool.free_head != NULL){
        FreeBlock* free_block = gMemPool.free_head;
        gMemPool.free_head = gMemPool.free_head->next_block;
        gMemPool.free_blocks--;

        return (void*) free_block;
    }
    //ELSE
    //base case no free blocks found
    return NULL; 
}

//free(ptr) — return a block to the pool
void freeBlock(FreeBlock* return_block){
    if (return_block == NULL || (return_block == gMemPool.free_head)) return; //check for valid pointer AND that we are double freeing the same block
    return_block->next_block = gMemPool.free_head;
    gMemPool.free_head = return_block;
    gMemPool.free_blocks++;
}

int main() {

    return 0;
}