<h2><a href="https://leetcode.com/problems/single-element-in-a-sorted-array">Single Element in a Sorted Array</a></h2> <img src='https://img.shields.io/badge/Difficulty-Medium-orange' alt='Difficulty: Medium' /><hr><p>You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.</p>

<p>Return <em>the single element that appears only once</em>.</p>

<p>Your solution must run in <code>O(log n)</code> time and <code>O(1)</code> space.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [1,1,2,3,3,4,4,8,8]
<strong>Output:</strong> 2
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [3,3,7,7,10,11,11]
<strong>Output:</strong> 10
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>0 &lt;= nums[i] &lt;= 10<sup>5</sup></code></li>
</ul>


<h1>My Noes</h1>
**Submission Notes:**

- **Problem Description**: The code aims to find the single non-duplicate element in a sorted array where each element appears exactly twice, except for one element that appears once.

- **Logic Overview**:
  - The algorithm utilizes the property of pairs in the array being in an even-odd or odd-even sequence around the single non-duplicate element.
  - The eliminator if condition checks for this property to determine which half of the array to search in, based on the index of the midpoint (`mid`).

- **Eliminator If Condition Explanation**:
  - If `mid` is at an even index (`mid % 2 == 0`) and `nums[mid]` is equal to `nums[mid+1]`, or if `mid` is at an odd index (`mid % 2 == 1`) and `nums[mid]` is equal to `nums[mid-1]`, then we know that the single non-duplicate element cannot be in the left half of the array up to `mid`.
  - Conversely, if `mid` is at an odd index and `nums[mid]` is equal to `nums[mid+1]`, or if `mid` is at an even index and `nums[mid]` is equal to `nums[mid-1]`, then we know that the single non-duplicate element cannot be in the right half of the array starting from `mid`.

- **Binary Search Approach**:
  - The code performs a binary search using `low` and `high` pointers, updating them based on the eliminator conditions until the single non-duplicate element is found.

- **Edge Cases Handling**:
  - The code handles edge cases where the array contains only one element (`sz == 1`) or the single non-duplicate element is at either end of the array.

- **Complexity Analysis**:
  - Time Complexity: O(log N), where N is the number of elements in the input array.
  - Space Complexity: O(1), as the algorithm uses a constant amount of extra space regardless of the input size.

- **Testing and Validation**:
  - The code has been tested with various test cases, including arrays with different sizes and arrangements of elements.

- **Conclusion**:
  - The code efficiently finds the single non-duplicate element in a sorted array by leveraging the even-odd pairing property and applying a binary search approach, ensuring optimal time complexity.
