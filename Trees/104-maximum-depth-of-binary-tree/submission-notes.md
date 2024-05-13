
## Maximum Depth of Binary Tree

### Problem:
Given a binary tree, determine its maximum depth. The maximum depth is defined as the number of nodes along the longest path from the root node down to the farthest leaf node.

### Solution Approach:
1. Initialize two variables `x` and `y` to store the maximum depths of the left and right subtrees, respectively.
2. If the root node is null, return 0 (base case for empty tree).
3. Recursively calculate the maximum depth of the left subtree (`x`) using `maxDepth(root->left)`.
4. Recursively calculate the maximum depth of the right subtree (`y`) using `maxDepth(root->right)`.
5. Compare `x` and `y`, and return the maximum depth among them plus 1 (adding 1 for the current node).

### Complexity Analysis:
- Time Complexity: O(N), where N is the number of nodes in the binary tree. Each node is visited exactly once during the depth calculation.
- Space Complexity: O(H), where H is the height of the binary tree. The space used by the recursive calls is proportional to the height of the tree.

This approach efficiently computes the maximum depth of a binary tree by recursively calculating the depths of its left and right subtrees.

