# Submission Notes for Insert into BST

## Problem Statement
The task is to insert a new node into a binary search tree (BST). Given a root node of a BST and a value to insert, the function should insert a new node with the given value into the BST such that the tree remains a valid BST. If the tree is empty, the new node becomes the root.

## Approach
The approach to solve this problem involves traversing the BST to find the correct position for the new node and then inserting it. The key steps are:

1. **Check for Empty Tree**: If the root is `NULL`, it means the tree is empty. In this case, create a new node with the given value and return it as the root.

2. **Traversal**: Traverse the tree to find the correct position for the new node. This is done by comparing the given value with the values of the nodes in the tree. If the value is less than the current node's value, move to the left child; otherwise, move to the right child. Keep track of the last visited node (`tail`) as this will be the parent of the new node.

3. **Insertion**: Once the correct position is found, create a new node with the given value. If the tree was empty (i.e., `tail` is `NULL`), assign the new node to the root. Otherwise, assign the new node to the left or right child of the `tail` node, depending on whether the value is less than or greater than the `tail` node's value.

4. **Return Value**: Return the root of the modified tree.

## Code Walkthrough
The code begins by checking if the root is `NULL`. If so, it creates a new node with the given value and returns it as the root. Otherwise, it traverses the tree to find the correct position for the new node. After finding the correct position, it creates a new node and inserts it into the tree. Finally, it returns the root of the modified tree.

## Time Complexity
The time complexity of this algorithm is O(h), where h is the height of the tree. This is because in the worst case, the algorithm needs to traverse from the root to the deepest leaf node.

## Space Complexity
The space complexity is O(1), assuming a balanced tree. However, in the worst case (unbalanced tree), it can go up to O(h) due to the space required for the recursion stack.

## Conclusion
This solution effectively inserts a new node into a binary search tree by traversing the tree to find the correct position and then inserting the new node. It handles the case where the tree is initially empty and ensures that the tree remains a valid BST after the insertion.
