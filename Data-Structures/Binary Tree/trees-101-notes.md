# What is it?
It is a non-linear data structure in which elements are ordered in a hierarchical manner.

**Key vocab:**
1. *root* -> node at the top level of the tree.
2. *leafs* -> nodes without children.
3. *children node* -> children to the relation of the node above it.
4.  *parent node* -> node that has 'children' or nodes that are connected to it and are below it.
5. *height of a tree* -> the longest path from root to the lowest leaf (lowest level of the tree).
6. *tree order* -> the max number of children any node may have. 

***What are some tree types?***
1. **n-ary tree:** limits each node to n amount of children.
2. **binary trees ([[binary-tree_notes]]):** limits each node to 2 children.
3. **balanced tree (general):** if all nodes are withing 1 level of each other. (Eg: branch 1->lvl 1 and branch 2->lvl2)
4. **unbalanced tree (general):** if nodes break the above rule (Eg: branch 1->lvl1 and branch 2->lvl5).
5. **complete tree:** meets these criteria
	1. balanced tree.
	2. all leaves at the the bottom level are on the **left side**. 
	3. $2^k$ nodes at every level k except the last where the nodes must be leftmost.
6. **full tree:** n-ary tree that meets these criteria
	1. all leaves of the tree are at the same level.
	2. every node is either a leaf OR has exactly n children.
7. **expression tree**: type of tree where:
	1. nodes represent math operators.
	2. leafs represent operands.
	3. encodes the order of operations by itself.

**balanced n-array tree** has a height of $\log_{n}m$ and **balanced binary tree** has a height of $\log_{2}m$

## How to work with it?
To start this it is essential to know strategies on implementing them then discuss traversal methods.

### What are implementation strategies?
1. **Linked structure**
	- pointer to the value at the node.
	- n amount of pointers to the n amount of children.
	- (optional) pointer to its parent.
2. **Array structure (binary tree)**
	- $n$ element is parent, its left child is $2*n +1$ and its right child is $2 * (n+1)$.


*Array implementations of binary trees seem to be the worst way of doing this.*

### What are some traversal strategies?
THREE METHODS (Only applies to DFS):

* **preorder** - ROOT -> LEFT -> RIGHT
* **inorder** - LEFT -> ROOT -> RIGHT
* **postorder** - LEFT -> RIGHT -> ROOT

BFS:
- Each level then next (level order traversal).

### Why does it exist?
There are few use cases:
1. using trees for implementing data structures can improve time complexity. Eg: list's find() could go from O(n) to O (log n).


2. specific problems:
    * When hierarchical relationships exist (e.g., file systems, organizational structures).
    * For searching operations (e.g., binary search trees).
    * When balancing operations are necessary (e.g., AVL trees, Red-Black trees).
    * For implementing heaps (e.g., priority queues).