### Comparison of Combination Sum Problems

We have discussed three different combination sum problems today. Let's compare their underlying conditions and how the code differs for each.

### 1. Combination Sum (LeetCode Problem 39)

**Problem Statement:**
Find all unique combinations in `candidates` where the candidate numbers sum to `target`. Each number in `candidates` can be used an unlimited number of times.

**Key Conditions:**
- Each number can be reused multiple times.
- Return all unique combinations.

**Code Implementation:**
```cpp
class Solution {
public:
    void backTrack(vector<vector<int>>& result, vector<int>& combination, vector<int>& candidates, int target, int start) {
        if (target == 0) {  // Base case: if target is 0, add the current combination to the result
            result.push_back(combination);
            return;
        }
        if (target < 0) return;  // Base case: if target is less than 0, return

        for (int i = start; i < candidates.size(); ++i) {
            combination.push_back(candidates[i]);  // Include the current element
            backTrack(result, combination, candidates, target - candidates[i], i);  // Recursive call with the same start index
            combination.pop_back();  // Backtrack by removing the last added element
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> combination;
        backTrack(result, combination, candidates, target, 0);
        return result;
    }
};
```

**Differences:**
- The same number can be reused multiple times, so the recursive call keeps the same start index (`i`).
- No need to skip duplicates within the `candidates` array since multiple uses are allowed.

### 2. Combination Sum II (LeetCode Problem 40)

**Problem Statement:**
Find all unique combinations in `candidates` where the candidate numbers sum to `target`. Each number in `candidates` can be used at most once.

**Key Conditions:**
- Each number can be used only once.
- Avoid duplicate combinations in the result.

**Code Implementation:**
```cpp
class Solution {
public:
    void backTrack(vector<vector<int>>& result, vector<int>& combination, vector<int>& candidates, int target, int start) {
        if (target == 0) {  // Base case: if target is 0, add the current combination to the result
            result.push_back(combination);
            return;
        }
        if (target < 0) return;  // Base case: if target is less than 0, return

        for (int i = start; i < candidates.size(); ++i) {
            if (i > start && candidates[i] == candidates[i - 1]) continue;  // Skip duplicates
            combination.push_back(candidates[i]);  // Include the current element
            backTrack(result, combination, candidates, target - candidates[i], i + 1);  // Recursive call with next start index
            combination.pop_back();  // Backtrack by removing the last added element
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> combination;
        sort(candidates.begin(), candidates.end());  // Sort to handle duplicates
        backTrack(result, combination, candidates, target, 0);
        return result;
    }
};
```

**Differences:**
- Each number can be used only once, so the recursive call moves to the next index (`i + 1`).
- Sorting the array and skipping duplicates within the same recursion level (`if (i > start && candidates[i] == candidates[i - 1]) continue`).

### 3. Combination Sum III (LeetCode Problem 216)

**Problem Statement:**
Find all valid combinations of `k` numbers that sum up to `n` using numbers from 1 to 9, each number used at most once.

**Key Conditions:**
- Only numbers 1 through 9 are used.
- Each number can be used only once.
- The combination must have exactly `k` numbers.

**Code Implementation:**
```cpp
class Solution {
public:
    void backtrack(int k, int n, vector<vector<int>>& result, vector<int>& combination, int start) {
        if (combination.size() == k && n == 0) {  // Base case: valid combination
            result.push_back(combination);
            return;
        }
        if (combination.size() > k || n < 0) return;  // Invalid combination
        
        for (int i = start; i <= 9; ++i) {
            combination.push_back(i);  // Include current number
            backtrack(k, n - i, result, combination, i + 1);  // Recursive call with next number
            combination.pop_back();  // Backtrack
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> combination;
        backtrack(k, n, result, combination, 1);  // Start from number 1
        return result;
    }
};
```

**Differences:**
- Specific range of numbers (1 to 9).
- Must form combinations of exactly `k` numbers.
- Similar to Combination Sum II, each number can be used only once, and the recursion moves to the next number (`i + 1`).
- The base case checks both the size of the combination and the sum (`if (combination.size() == k && n == 0)`).

### Summary:

- **Combination Sum:** Allows repeated use of numbers. Recursion maintains the same start index to allow reuse.
- **Combination Sum II:** Does not allow repeated use of numbers. Recursion moves to the next index and skips duplicates.
- **Combination Sum III:** Uses numbers from a fixed range (1-9) and requires exactly `k` numbers in each combination. Similar to Combination Sum II in terms of number usage but includes additional constraints on the size of combinations.

Understanding these differences helps in correctly implementing the backtracking solutions tailored to each problem's unique constraints and requirements.
