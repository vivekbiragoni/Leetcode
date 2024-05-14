# Submission Note: Finding the Lowest Common Ancestor in a Binary Search Tree

## Objective
To find the lowest common ancestor (LCA) of two nodes `p` and `q` in a binary search tree (BST).

## Approach
The approach is based on the property of BSTs where all nodes to the left of a node have values less than the node, and all nodes to the right have values greater than the node.

### Method
- Start from the root of the BST.
- If the current node's value is less than both `p` and `q`, then the LCA must be in the right subtree. Recursively search the right subtree.
- If the current node's value is greater than both `p` and `q`, then the LCA must be in the left subtree. Recursively search the left subtree.
- If neither of the above conditions is met, the current node is the LCA.

### Time Complexity
- O(h), where h is the height of the tree. This is because in the worst case, we might need to traverse down the tree to find the LCA.

### Space Complexity
- O(1), assuming the tree is not a skewed tree. In a skewed tree, the space complexity could be O(h) due to the maximum depth of the recursive call stack.

### Pros
- Efficient for balanced BSTs due to the binary search property.
- Simple and intuitive approach that leverages the BST property.

### Cons
- Potentially inefficient for skewed BSTs due to the maximum depth of the recursive call stack.

## Conclusion
The provided solution effectively finds the lowest common ancestor of two nodes in a BST by leveraging the BST property. It is efficient for balanced trees but may not perform well for skewed trees due to the potential for deep recursion. This method is a straightforward application of the BST property to solve the problem.
