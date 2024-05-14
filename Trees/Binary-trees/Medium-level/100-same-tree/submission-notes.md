

- **Problem and Approach**:
  - Problem: Check if two binary trees are the same.
  - Approach: Use recursive preorder traversal to compare corresponding nodes in both trees.

- **Methodology**:
  - The function `isSameTree` takes two TreeNode pointers as input, representing the roots of two binary trees `p` and `q`.
  - If either `p` or `q` is `NULL`, return true if both are `NULL`, indicating the trees are same at that position.
  - Recursively check if the values of corresponding nodes in both trees are equal, and also check the left and right subtrees using the same approach.
  - Return true if all nodes in both trees are equal, otherwise return false.

- **Time Complexity**:
  - The time complexity is O(N), where N is the number of nodes in the smaller of the two trees.
  - This is because we traverse through all nodes once during the recursive comparison.

- **Space Complexity**:
  - The space complexity is O(H), where H is the height of the smaller of the two trees.
  - This is due to the recursive calls on the stack, which can go up to the height of the smaller tree.

