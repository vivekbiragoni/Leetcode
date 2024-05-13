

- **Problem and Approach**:
  - Problem: Find the maximum path sum in a binary tree.
  - Approach: Use a recursive approach to traverse the tree and calculate the maximum path sum at each node.

- **Methodology**:
  - Initialize `maxSum` with `INT_MIN` to handle negative values.
  - Use `maxSumHelper` function to traverse the tree recursively.
  - At each node, calculate the maximum sum considering both left and right subtrees along with the current node value.
  - Update `maxSum` with the maximum path sum encountered so far.
  - Return the maximum path sum.

- **Changes to maxDepth**:
  - The `maxDepth` function has been modified to handle the maximum path sum calculation.
  - Instead of returning the depth, it now returns the maximum path sum considering the subtree rooted at the current node.
  - Negative contributions are ignored by using `max(0, ...)` to prevent them from affecting the overall maximum path sum.

- **Time Complexity**: 
  - The time complexity is O(N), where N is the number of nodes in the binary tree.
  - This is because we visit each node once during the recursive traversal.

- **Space Complexity**:
  - The space complexity is O(H), where H is the height of the binary tree.
  - This is due to the recursive calls on the stack, which can go up to the height of the tree.

