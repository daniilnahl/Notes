# What is Cache and why is it important?
Memory placed in between processor and main memory and is responsible for holding data from main memory for fast retrieval by CPU. 
- Cache consists of a collection of blocks where each block has a tag. 
- A tag that corresponds to the location in the main memory of the data.
- data from that specific memory address.

**Cache hit** signifies a processor finding required data within cache. 
**Cache miss** signies a processor not finding required data within cache.

## What is Cache and types of it (expanded)?
When a 'word' (2 bytes) is not found in cache it must be fetched from lower memory levels (another cache -> main memory.)
- multiple words are called a block.
- each cache block includes a tag to indicate which memory address it corresponds to.

*where are blocks placed in cache?*

1. Using **set associative scheme**:
    - *set* is a group of blocks.
    - Block is mapped to the set and can be place anywhere within that set.
    - Finding a block consists of setting the address at the *set* then searching the set in parallel.

2. Using **direct-mapped cache**:
    - one *set* per one block.

3. Using **fully associative cache**:
    - there is one *set* for all blocks.

4. **L1**
    - register directly in the CPU. Holds address registers, program counters, etc.

5. **L2**
    - larger than L1.
    - either in CPU or standalone chip.

6. **L3**
    - Customized memory designed to speed up L1 and L2.

## What does it mean to 'cache' something?
Caching is taking data and storing it for a temporary time period.




