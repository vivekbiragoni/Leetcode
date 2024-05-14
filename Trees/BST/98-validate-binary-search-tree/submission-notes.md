# Submission Note: Validating Binary Search Tree (BST)

## Objective
To validate if a given binary tree is a valid Binary Search Tree (BST).

## Approach 1: Using In-Order Traversal with Manual Strictly Sorted Check

### Method
- Perform an in-order traversal of the tree and store the traversal results in a vector.
- Manually iterate through the vector to check if each element is strictly less than the next one.

### Space Complexity
- O(n) due to the additional vector used to store the traversal results, where n is the number of nodes in the tree.

### Time Complexity
- O(n) for the in-order traversal and the manual check, as each node is visited once.

### Pros
- Efficient in terms of space as it doesn't require additional space for sorting or any built-in function that might introduce overhead.
- Directly validates the BST property by comparing each node's value with its successor.

### Cons
- The manual check for strict ascending order requires additional code and might be slightly less intuitive than using a built-in function.

## Approach 2: Using In-Order Traversal with Stack and Previous Node Tracking

### Method
- Perform an in-order traversal using a stack to avoid recursion.
- Introduce a `prev` pointer to keep track of the previous node visited.
- Check if the current node's value is strictly greater than the previous node's value.

### Space Complexity
- O(n) for the stack in the worst case (a skewed tree), where each node pushed onto the stack adds a new layer to the stack.

### Time Complexity
- O(n) for a balanced tree and O(2^n) for a skewed tree, as each node is visited once.

### Pros
- Efficient in terms of space as it doesn't require an additional vector for storing the traversal results.
- Maintains the BST property by directly comparing each node's value with its predecessor.

### Cons
- The logic is slightly more complex due to the need to track the previous node and perform the comparison within the traversal loop.

## Conclusion
The first approach, using in-order traversal with a manual check for strictly sortedness, is preferred for validating a BST due to its space efficiency and direct validation of the BST property without the need for additional space or built-in functions. This method is particularly suitable for large trees or when space efficiency is a critical factor.
