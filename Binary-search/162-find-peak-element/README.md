<h2><a href="https://leetcode.com/problems/find-peak-element">Find Peak Element</a></h2> <img src='https://img.shields.io/badge/Difficulty-Medium-orange' alt='Difficulty: Medium' /><hr><p>A peak element is an element that is strictly greater than its neighbors.</p>

<p>Given a <strong>0-indexed</strong> integer array <code>nums</code>, find a peak element, and return its index. If the array contains multiple peaks, return the index to <strong>any of the peaks</strong>.</p>

<p>You may imagine that <code>nums[-1] = nums[n] = -&infin;</code>. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.</p>

<p>You must write an algorithm that runs in <code>O(log n)</code> time.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,3,1]
<strong>Output:</strong> 2
<strong>Explanation:</strong> 3 is a peak element and your function should return the index number 2.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1,2,1,3,5,6,4]
<strong>Output:</strong> 5
<strong>Explanation:</strong> Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>-2<sup>31</sup> &lt;= nums[i] &lt;= 2<sup>31</sup> - 1</code></li>
	<li><code>nums[i] != nums[i + 1]</code> for all valid <code>i</code>.</li>
</ul>

<h1>My notes</h1>

# Submission Notes

## Problem: Finding Peak Element in an Array

### Intuition Behind the Code
- The code employs a binary search strategy to locate a peak element efficiently.
- It begins by checking if the array has only one element (`n == 1`) or if the first or last element qualifies as a peak.
- In cases where the first or last element is a peak, the code returns the corresponding index (`0` or `n-1`).
- For arrays with more than one element and no peak at the extremes, it sets up a binary search range (`low` and `high`) excluding the first and last elements.
- During each iteration, the code evaluates the midpoint (`mid`) to determine if it is a peak by comparing it with its neighbors.
  - If `nums[mid]` is greater than both `nums[mid-1]` and `nums[mid+1]`, it returns `mid` as the peak element.
  - If `nums[mid]` is greater than only `nums[mid-1]`, it indicates an increasing curve towards the right, so the search range shifts right by setting `low = mid + 1`.
  - If `nums[mid]` is greater than only `nums[mid+1]`, it suggests a decreasing curve towards the right, so the search range shifts left by setting `high = mid - 1`.
- This process repeats until `low` is no longer less than or equal to `high`, signifying that the peak element has not been found.

### Complexity Analysis
- **Time Complexity:** O(log N), where N is the number of elements in the input array.
- **Space Complexity:** O(1), as the algorithm uses a constant amount of extra space regardless of the input size.

### Edge Cases Handling
- The code handles scenarios where the array contains only one element or where the first or last element is a peak.

### Testing and Validation
- The code has undergone testing with various test cases, including arrays of different sizes and configurations of peak positions.

### Conclusion
- The code efficiently identifies a peak element in an array using binary search, leveraging the characteristics of peak elements being greater than their neighbors. This approach ensures optimal time complexity for locating the peak element.

