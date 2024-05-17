

# Submission Notes: House Robber

## Approach Used: Dynamic Programming

### Problem Description
Given an array of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police. You cannot rob two adjacent houses.

### Recursive and Dynamic Programming Approach
The solution is implemented using dynamic programming to optimize the recursive approach. Here’s a detailed breakdown of the approach:

1. **Recursive Function (`helper`)**:
   - This function is designed to solve the problem using recursion.
   - **Base Cases**:
     - If the index is less than 0, return 0 (no houses to rob).
     - If the index is 0, return the amount in the first house (only one house to rob).
   - **Recursive Cases**:
     - Calculate the maximum amount by either picking or not picking the current house.
     - Use the formula:
       - `pick = nums[index] + helper(nums, index - 2)`
       - `not_pick = helper(nums, index - 1)`
     - Return the maximum of `pick` and `not_pick`.

2. **Memoization**:
   - To optimize the recursive approach, memoization is used.
   - An array `dp` is used to store the results of subproblems.
   - If a subproblem is already solved (i.e., `dp[index] != -1`), return the stored result.
   - This avoids redundant calculations and improves efficiency.

3. **Dynamic Programming (Iterative)**:
   - Instead of using recursion, an iterative approach with dynamic programming can be used.
   - Two variables `prev` and `prev2` are used to keep track of the maximum amount robbed from previous houses.
   - Iterate through the array and update these variables based on whether the current house is picked or not.
   - This method has a time complexity of O(n) and space complexity of O(1).

### Implementation Details
- **Main Function (`rob`)**:
  - Handles the base case where there is only one house.
  - Calls the dynamic programming function to compute the maximum amount that can be robbed.

```cpp
class Solution {
public:
    int rob(vector<int>& arr) {
        int n = arr.size();
        long long int prev = arr[0];
        long long int prev2 = 0;

        for (int i = 1; i < n; i++) {
            long long int pick = arr[i];
            if (i > 1)
                pick += prev2;
            long long int nonPick = 0 + prev;

            long long int cur_i = max(pick, nonPick);
            prev2 = prev;
            prev = cur_i;
        }
        return prev;
    }
};
```

### Complexity Analysis
- **Time Complexity**: O(n)
  - The solution involves a single pass through the houses.
- **Space Complexity**: O(1)
  - Uses constant extra space for storing the previous results.

### Example Test Cases
- **Example 1**:
  - Input: `[2, 3, 2]`
  - Output: `3`
  - Explanation: Rob houses 1 and 3.
- **Example 2**:
  - Input: `[1, 2, 3, 1]`
  - Output: `4`
  - Explanation: Rob houses 1 and 3.

### Constraints
- The number of houses (n) is at least 1 and at most 100.
- Each house contains a non-negative integer representing the amount of money.

