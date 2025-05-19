## 1. What is it?

A Binary Tree is a hierarchical data structure where each node has at most TWO children: left and right child.

## 2. Why was this created?

This data structure provides an efficient way to organize, store, and retrieve hierarchical data. They solve problems where fast insertion, deletion, and lookup operations are needed, such as in search trees, heaps, and expression trees.

## 3. How does it work?

A binary tree consists of nodes where:

* Each node contains a value.
* Each node has a left and right child, which may be `NULL` (or `None` in Python).
* The ROOT node is the starting point of the tree.

## 4. How to TRAVERSE?

THREE METHODS:

* **preorder** - ROOT -> LEFT -> RIGHT
* **inorder** - LEFT -> ROOT -> RIGHT
* **postorder** - LEFT -> RIGHT -> ROOT

## 5. When to use?

* When hierarchical relationships exist (e.g., file systems, organizational structures).
* For searching operations (e.g., binary search trees).
* When balancing operations are necessary (e.g., AVL trees, Red-Black trees).
* For implementing heaps (e.g., priority queues).