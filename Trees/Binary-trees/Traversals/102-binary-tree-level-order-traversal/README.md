<h2><a href="https://leetcode.com/problems/binary-tree-level-order-traversal">Binary Tree Level Order Traversal</a></h2> <img src='https://img.shields.io/badge/Difficulty-Medium-orange' alt='Difficulty: Medium' /><hr><p>Given the <code>root</code> of a binary tree, return <em>the level order traversal of its nodes&#39; values</em>. (i.e., from left to right, level by level).</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/19/tree1.jpg" style="width: 277px; height: 302px;" />
<pre>
<strong>Input:</strong> root = [3,9,20,null,null,15,7]
<strong>Output:</strong> [[3],[9,20],[15,7]]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> root = [1]
<strong>Output:</strong> [[1]]
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> root = []
<strong>Output:</strong> []
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[0, 2000]</code>.</li>
	<li><code>-1000 &lt;= Node.val &lt;= 1000</code></li>
</ul>




## Submission Notes

### Problem: Binary Tree Level Order Traversal

#### Approach:
- This solution uses a queue-based approach to perform level order traversal of a binary tree.
- It processes nodes level by level, pushing each level's values into the result vector.

#### Algorithm:
1. Initialize an empty queue `q` and a vector of vectors `result` to store the level order traversal.
2. Push the root node into the queue `q`.
3. While the queue is not empty:
   - Initialize an empty vector `currentLevel` to store the values of the current level.
   - Get the size of the queue (`levelSize`) to process nodes level by level.
   - Iterate `levelSize` times:
     - Dequeue a node `p` from the front of the queue.
     - Push `p->val` into `currentLevel`.
     - Enqueue `p->left` and `p->right` if they exist.
   - Push `currentLevel` into the `result` vector.
4. Return the `result` vector containing the level order traversal.

#### Complexity Analysis:
- **Time Complexity:** O(N), where N is the number of nodes in the binary tree. Each node is processed exactly once.
- **Space Complexity:** O(N) due to the queue `q` and the `result` vector storing the level order traversal.


