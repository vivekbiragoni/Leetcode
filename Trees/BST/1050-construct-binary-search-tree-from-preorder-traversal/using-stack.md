Submission Notes: abdulbari's mehtod

### Problem Description:
The task involves constructing a Binary Search Tree (BST) from its preorder traversal. Given an array representing the preorder traversal of a BST, the goal is to recreate the original BST.

### Approach:
1. **Iterative Construction Using a Stack**: The solution employs an iterative approach with a stack to manage the parent nodes of the BST being constructed. This method avoids recursion, potentially improving performance for large inputs.

2. **Stack Usage**:
   - The stack stores pointers to the nodes currently under consideration for linking their children. Initially, only the root node is pushed onto the stack.
   - As the algorithm progresses, it determines whether each subsequent node in the preorder array should be linked as a left or right child of the current node pointed to by the top of the stack.

3. **Node Creation and Linking**:
   - New nodes are created for each element in the preorder array starting from the second element (since the first element is already assigned to the root).
   - The algorithm checks if the current node should be a left or right child based on its value relative to the current top node in the stack.
   - If the current node is a left child, it is linked to the left of the current top node, and then pushed onto the stack.
   - If the current node is a right child, the algorithm pops from the stack until it finds a node whose value is less than the current node's value, indicating the correct parent node. The current node is then linked to the right of this parent node, and pushed back onto the stack.

4. **Handling Edge Cases**:
   - The base case for an empty input array is handled by returning `nullptr`, indicating that no BST can be constructed.

5. **Memory Management**:
   - Dynamic memory allocation is used to create new nodes. Care should be taken to properly manage memory to avoid leaks.

### Code Review:
- **Efficiency**: The use of a stack ensures that the algorithm traverses the preorder array once, making it efficient for constructing the BST.
- **Readability**: The code is structured clearly, with logical flow and comments explaining key steps.
- **Error Handling**: Proper handling of edge cases, such as an empty input array, enhances the robustness of the solution.

### Potential Improvements:
- **Optimization**: While the current approach is efficient, further optimizations might involve reducing the number of stack operations or refining the conditions for determining left vs. right children.
- **Testing**: Extensive testing with various test cases, including edge cases like trees with many levels or skewed trees, would help validate the solution's correctness and efficiency.

### Conclusion:
This solution provides a practical and efficient way to construct a BST from its preorder traversal using an iterative approach. By carefully managing the stack and appropriately linking nodes, it successfully recreates the original BST.
