# Submission Notes for Search in a Binary Search Tree

## Problem Statement
The problem is to search for a specific value in a binary search tree (BST). Given a root node of a BST and a value to search for, return the node containing the value if it exists, or `nullptr` if it does not.

## Approach
The approach to solve this problem is straightforward, given the properties of a binary search tree. In a BST, all nodes to the left of a node have values less than the node's value, and all nodes to the right have values greater than the node's value. This property allows us to perform a binary search-like traversal to find the target value.

1. **Initialization**: Start at the root of the BST.

2. **Traversal**: While the current node is not `nullptr`, compare the target value with the current node's value.
   - If the target value is equal to the current node's value, return the current node.
   - If the target value is less than the current node's value, move to the left child of the current node.
   - If the target value is greater than the current node's value, move to the right child of the current node.

3. **Termination**: If the target value is not found in the tree, return `nullptr`.

## Code Walkthrough
The code begins by checking if the root is `nullptr`. If so, it immediately returns `nullptr` since an empty tree cannot contain the target value.

The main loop of the algorithm runs until the current node is `nullptr`. Inside the loop, it compares the target value with the current node's value. If the target value is found, it returns the current node. If the target value is less than the current node's value, it moves to the left child. If the target value is greater, it moves to the right child.

## Time Complexity
The time complexity of this algorithm is O(h), where h is the height of the tree. In the worst case, the algorithm needs to traverse from the root to the deepest leaf node.

## Space Complexity
The space complexity is O(1), as the algorithm only uses a constant amount of space to store the current node and the target value. It does not use any additional data structures that grow with the size of the input.

## Conclusion
This solution effectively solves the search problem in a binary search tree by leveraging the tree's properties to guide the traversal. The use of a simple while loop and conditional checks makes the algorithm efficient and easy to understand.
