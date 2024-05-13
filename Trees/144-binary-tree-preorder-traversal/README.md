<h2><a href="https://leetcode.com/problems/binary-tree-preorder-traversal">Binary Tree Preorder Traversal</a></h2> <img src='https://img.shields.io/badge/Difficulty-Easy-brightgreen' alt='Difficulty: Easy' /><hr><p>Given the <code>root</code> of a binary tree, return <em>the preorder traversal of its nodes&#39; values</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/15/inorder_1.jpg" style="width: 125px; height: 200px;" />
<pre>
<strong>Input:</strong> root = [1,null,2,3]
<strong>Output:</strong> [1,2,3]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> root = []
<strong>Output:</strong> []
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> root = [1]
<strong>Output:</strong> [1]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[0, 100]</code>.</li>
	<li><code>-100 &lt;= Node.val &lt;= 100</code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong> Recursive solution is trivial, could you do it iteratively?</p>






# Problem: Preorder Traversal of Binary Tree based on the recursion

#### Approach:
This solution uses a recursion-based approach to perform a preorder traversal of a binary tree. The main logic involves visiting each node in the tree in the order of root, left subtree, and right subtree.

#### Algorithm:
1. Initialize an empty vector `result` to store the preorder traversal elements.
2. Implement a helper function `preorderTraversalHelper` that takes the root of the tree and the `result` vector as parameters.
3. In the `preorderTraversalHelper` function:
   - If the root is not `nullptr`, push the value of the current node (`root->val`) into the `result` vector.
   - Recursively call `preorderTraversalHelper` for the left subtree of the current node (`root->left`) and then for the right subtree of the current node (`root->right`).
4. Call the `preorderTraversalHelper` function with the root of the binary tree and the `result` vector from the `preorderTraversal` function.
5. Return the `result` vector containing the preorder traversal elements.

#### Complexity Analysis:
- **Time Complexity:** The time complexity of the algorithm is O(N), where N is the number of nodes in the binary tree. This is because the algorithm visits each node exactly once.
- **Space Complexity:** The space complexity is also O(N), where N is the number of nodes. This is due to the space used by the recursive call stack.

This approach is straightforward and commonly used for tree traversal algorithms, providing an intuitive way to visit nodes in the desired order.

---

Feel free to customize or expand upon these notes based on additional details or specific requirements for your submission on LeetCode.
