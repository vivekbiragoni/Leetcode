# Submission Notes for Zigzag Level Order Traversal

## Problem Statement
The problem is to perform a zigzag level order traversal of a binary tree. In a zigzag level order traversal, the nodes at each level are printed from left to right on even levels and from right to left on odd levels.

## Approach
The approach to solve this problem involves using a breadth-first search (BFS) algorithm with a slight modification to handle the zigzag order. The key steps are:

1. **Initialization**: Create an empty queue to hold the nodes of the tree and a boolean flag `leftToRight` to indicate the direction of traversal. Initially, set `leftToRight` to `true`.

2. **BFS with Modification**: Perform a BFS traversal. For each level, instead of simply adding nodes to the result in the order they are visited, we need to reverse the order for odd levels. This is achieved by calculating the index at which each node's value should be placed in the current level's row based on the `leftToRight` flag.

3. **Level Traversal**: For each level, calculate the size of the current level (`sz`), and create a row of size `sz`. Then, for each node in the current level, calculate its index in the row based on the `leftToRight` flag. Add the node's value to the row at the calculated index. After processing all nodes at the current level, add the row to the result and flip the `leftToRight` flag for the next level.

4. **Termination**: The traversal continues until the queue is empty, indicating that all nodes have been visited.

## Code Walkthrough
The code begins by checking if the root is `nullptr`. If so, it returns an empty result. Otherwise, it initializes a queue with the root node and sets the `leftToRight` flag to `true`.

The main loop of the algorithm runs until the queue is empty. For each level, it calculates the size of the level and creates a row of that size. It then iterates over each node at the current level, calculating the index at which to place the node's value in the row based on the `leftToRight` flag. After processing all nodes at the current level, it adds the row to the result and flips the `leftToRight` flag for the next level.

## Time Complexity
The time complexity of this algorithm is O(n), where n is the number of nodes in the tree. This is because each node is visited exactly once.

## Space Complexity
The space complexity is also O(n), where n is the number of nodes in the tree. This is due to the space required to store the nodes in the queue and the result vector.

## Conclusion
This solution effectively solves the zigzag level order traversal problem by modifying the standard BFS algorithm to account for the zigzag order. The use of a queue ensures that nodes are processed level by level, and the `leftToRight` flag allows for the easy adjustment of the traversal direction at each level.
