# What is a heap?
1. An almost complete binary. 
2. To access branches of a node:    
    - 2 * i for left child 
    - 2 * i + 1 for right child 
    - (i/2) for its parent
There are two kind:
- Max heap: value of a node i is less or equal to the value of its parent node. Meaning that the top of the tree has the highest value. Used for heapsort.
- Min heap: value of node i is greater or equal to the value of its parent node. Meaning that the top of tree has the lowest value. Used for priority queue.

## What are complexities of a heap?
- Insertion/Deletion: O (log n)
- Space: O (N)

## How is a heap different than a binary tree?
1. The rule of node i being less or greater than its parent node.
2. The requirement of each level to be filled before the next one can be used. Filled strictly left to right.

In contrast binary tree doesn't follow any type of sorting like in bullet point 1 and each node can have its branches go as deep as they want disregarding bullet point 2.

# When to use a heap?
Use in two instances:
    - Priority queue (min heap)
    - Heapsort (max heap)