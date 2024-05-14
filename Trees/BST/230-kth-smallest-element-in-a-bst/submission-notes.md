# Submission Notes for Finding the kth Smallest Element in BST

## Problem Statement
The task is to find the kth smallest element in a binary search tree (BST). Given a root node of a BST and an integer `k`, the function should return the kth smallest element in the BST. The elements are 1-indexed, meaning the first element is at index 1, the second element is at index 2, and so on.

## Approach
The approach to solve this problem involves performing an inorder traversal of the BST. Inorder traversal of a BST visits the nodes in ascending order, which makes it suitable for finding the kth smallest element. The steps are as follows:

1. **Inorder Traversal**: Traverse the BST in an inorder manner, which means visiting the left subtree, the current node, and then the right subtree. This traversal order ensures that the elements are visited in ascending order.

2. **Store Node Values**: As the traversal visits each node, store the node's value in a vector. This vector will contain the elements of the BST in ascending order.

3. **Return the kth Element**: After the traversal is complete, return the element at the kth index in the vector. Since the elements are 1-indexed, the kth element is at index `k-1` in the vector.

## Code Walkthrough
The code defines a `Solution` class with a public method `kthSmallest` and a private helper method `inorderTraversal`. The `kthSmallest` method performs the inorder traversal and returns the kth smallest element. The `inorderTraversal` method implements the inorder traversal logic using a stack to keep track of the nodes to be visited.

## Time Complexity
The time complexity of this algorithm is O(h + k), where h is the height of the tree and k is the value of the input parameter. This is because the inorder traversal visits each node once, and then it iterates through the vector to find the kth element, which takes O(k) time.

## Space Complexity
The space complexity is O(h), where h is the height of the tree. This is due to the space required for the stack used in the inorder traversal. In the worst case, the stack can hold all the nodes of the tree, which happens when the tree is skewed.

## Conclusion
This solution effectively finds the kth smallest element in a BST by performing an inorder traversal and returning the element at the kth index in the vector. It handles the 1-indexing of the problem statement correctly by adjusting the index when accessing the element in the vector.
