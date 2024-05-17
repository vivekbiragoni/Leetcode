
**Submission Notes: House Robber II**

**Approach Used: Dynamic Programming**

1. **Problem Description:**  
   - Given an array of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
   - The houses are arranged in a circle, which means the first and last houses are adjacent.

2. **Key Insight:**
   - The circular nature of the problem requires a modification of the classic "House Robber" problem.
   - To handle the circular condition, we solve two separate subproblems:
     1. Exclude the first house and consider the rest.
     2. Exclude the last house and consider the rest.
   - The final result is the maximum of these two subproblems.

3. **Implementation Details:**
   - **Dynamic Programming Function (`solve`)**: Solves the linear version of the problem using dynamic programming.
     - Uses two variables, `prev` and `prev2`, to keep track of the maximum amounts robbed from previous houses.
     - Iterates through the array and updates these variables based on whether the current house is picked or not.
   - **Main Function (`rob`)**:
     - Handles the edge case where there is only one house.
     - Creates two subarrays: one excluding the first house (`arr1`), and the other excluding the last house (`arr2`).
     - Uses the `solve` function to compute the maximum amount for both subarrays.
     - Returns the maximum of the two results.

4. **Complexity Analysis:**
   - **Time Complexity:** O(n)
     - The solution involves two passes through the houses (excluding the first and last house scenarios).
     - Each pass involves a linear scan through the houses.
   - **Space Complexity:** O(1)
     - Uses constant extra space for the dynamic programming solution (only a few variables are used).

5. **Example Test Cases:**
   - **Example 1:**
     - Input: `[2, 3, 2]`
     - Output: `3`
     - Explanation: Rob houses 2 and 3.
   - **Example 2:**
     - Input: `[1, 2, 3, 1]`
     - Output: `4`
     - Explanation: Rob houses 1 and 3.

6. **Constraints:**
   - The number of houses (n) is at least 1 and at most 100.
   - Each house contains a non-negative integer representing the amount of money.


