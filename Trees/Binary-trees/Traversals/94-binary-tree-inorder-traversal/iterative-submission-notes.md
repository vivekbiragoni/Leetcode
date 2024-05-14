

## Iterative Inorder Traversal of Binary Tree

### Problem:
Given a binary tree, perform an inorder traversal of its nodes iteratively.

### Solution Approach:
1. Initialize an empty stack `st` to store tree nodes.
2. Initialize an empty vector `traversal` to store the inorder traversal result.
3. Start with the root node.
4. While the current node is not null or the stack is not empty:
   - If the current node is not null:
     - Push the current node onto the stack.
     - Move to its left child.
   - If the current node is null (reached a leaf or finished left subtree traversal):
     - Pop a node from the stack (backtrack to its parent).
     - Add its value to the `traversal` vector.
     - Move to its right child (if exists).
5. Return the `traversal` vector containing the inorder traversal result.

### Complexity Analysis:
- Time Complexity: O(N), where N is the number of nodes in the binary tree. Each node is visited exactly once.
- Space Complexity: O(H), where H is the height of the binary tree. The stack space is proportional to the height of the tree.

This approach efficiently computes the inorder traversal of a binary tree without using recursion, utilizing a stack to manage node traversal order.
