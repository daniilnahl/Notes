/*
Notes:
1. add checks for failed allocation + parameters being nulls or 0s
2. add mechanism for dealing with double freeing
3. add alignment checks + padding
*/

#include <inttypes.h>
#include <stdlib.h>

typedef struct FreeBlock {
    struct FreeBlock* next_block;
} FreeBlock;

typedef struct MemPool {
    uint32_t block_count;
    uint32_t block_size;
    uint32_t free_blocks;
    struct FreeBlock* free_head;
    uint8_t* pool_start_addr;
} MemPool;

MemPool gMemPool;

void poolCreate(size_t capacity, size_t blockSize){
    gMemPool.block_count = capacity;
    gMemPool.block_size = blockSize;
    gMemPool.free_blocks = capacity;

    gMemPool.pool_start_addr = malloc(capacity * blockSize);
    if (gMemPool.pool_start_addr == NULL) return; //failed to allocate memory


    gMemPool.free_head = (FreeBlock*)gMemPool.pool_start_addr;
    FreeBlock* current = gMemPool.free_head;
    
    //allocate memory to each block
    for (size_t i = 1; i < capacity; i++){
        current->next_block = (FreeBlock*)(((uint8_t*) gMemPool.pool_start_addr) + (blockSize * i));
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
    return_block->next_block = gMemPool.free_head;
    gMemPool.free_head = return_block;
    gMemPool.free_blocks++;

}

int main() {

    return 0;
}