

### Problem Description:
The task is to construct a Binary Search Tree (BST) from its preorder traversal. A BST is a tree data structure where each node has at most two children, referred to as the left child and the right child. For each node, all elements in the left subtree are less than the node, and all elements in the right subtree are greater.

### Approach:
1. **Preorder Traversal**: Preorder traversal of a BST visits nodes in the order: Root, Left, Right. This property is leveraged to reconstruct the BST from its preorder traversal.

2. **Recursive Construction**:
   - The first element of the preorder traversal array is always the root of the BST.
   - To find the left subtree, we look for the smallest element that is larger than the current root. This can be done by recursively calling the `build` function with the same index until the condition fails.
   - Similarly, to find the right subtree, we look for the largest element that is smaller than the current root. This can be achieved by recursively calling the `build` function with the updated index and the current root value as the bound.

3. **Base Case**:
   - If the index equals the size of the preorder array or the next element in the preorder array is not larger than the bound, it means there are no more elements to process, and we return `NULL`.

4. **Memory Management**:
   - Each node is dynamically allocated using `new`. It's important to ensure proper memory management to avoid leaks.

### Code Explanation:
- **Function `bstFromPreorder`**: Initializes the recursive construction by calling the `build` function with the first element of the preorder array and an initial bound of `INT_MAX`.
- **Function `build`**: Recursively constructs the BST. It takes the preorder array, the current index (`i`), and a bound as arguments. The bound helps in determining when to stop looking for the right subtree.

### Submission Notes:
- Ensure that the code correctly handles edge cases, such as empty input arrays.
- Test the solution with various test cases, including those with duplicate values, to ensure correctness.
- Consider adding comments within the code to explain complex logic or decisions made during implementation.

### Potential Improvements:
- Optimize the search for the left and right subtrees to reduce the number of comparisons.
- Implement a destructor or a cleanup method to deallocate memory used by the BST nodes, ensuring no memory leaks.

### Conclusion:
This solution effectively utilizes the properties of preorder traversal to reconstruct a BST. However, attention should be paid to edge cases and memory management to ensure robustness and efficiency.
