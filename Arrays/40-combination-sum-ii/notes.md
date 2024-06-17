

### Problem Summary
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to the target. Each number in candidates may only be used once in the combination. The solution set must not contain duplicate combinations.

### Key Points
- **Input:**
  - `candidates`: An array of integers (each number can be used only once).
  - `target`: The target sum.
- **Output:**
  - A list of all unique combinations where the sum of numbers equals the target.
- **Constraints:**
  - Each number in `candidates` can be used only once.
  - The solution set must not contain duplicate combinations.

### Approach
1. **Sorting the Input:**
   - Sort the `candidates` array to handle duplicates easily.
   
2. **Backtracking:**
   - Use a helper function to perform backtracking.
   - Keep track of the current combination of numbers and their sum.
   - If the sum equals the target, add the combination to the result list.
   - If the sum exceeds the target, backtrack.
   - Skip duplicates to avoid redundant combinations.

3. **Skipping Duplicates:**
   - While iterating, if the current element is the same as the previous one (at the same recursive level), skip it.

### Algorithm
1. **Sort the `candidates` array.**
2. **Define the backtracking function:**
   - Parameters: the result list, current combination, remaining target, start index.
   - Base case:
     - If the target is 0, add the current combination to the result.
     - If the target is less than 0, return.
   - Recursive case:
     - Iterate over the `candidates` starting from the `start` index.
     - Skip duplicates.
     - Include the current element in the combination and recursively call the function with updated parameters.
     - Backtrack by removing the last added element.

### C++ Implementation
```cpp
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> combination;
        sort(candidates.begin(), candidates.end());  // Step 1: Sort the candidates array
        backTrack(result, combination, candidates, target, 0);  // Step 2: Call the backtracking function
        return result;
    }

private:
    void backTrack(vector<vector<int>>& result, vector<int>& combination, vector<int>& candidates, int target, int start) {
        if (target == 0) {  // Base case: if target is 0, add the current combination to the result
            result.push_back(combination);
            return;
        }
        if (target < 0) return;  // Base case: if target is less than 0, return

        for (int i = start; i < candidates.size(); ++i) {
            // Skip duplicates
            if (i > start && candidates[i] == candidates[i - 1]) continue;

            combination.push_back(candidates[i]);  // Include the current element
            backTrack(result, combination, candidates, target - candidates[i], i + 1);  // Recursive call with updated target and start index
            combination.pop_back();  // Backtrack by removing the last added element
        }
    }
};

// Example usage
int main() {
    Solution sol;
    vector<int> candidates1 = {10, 1, 2, 7, 6, 1, 5};
    int target1 = 8;
    vector<vector<int>> result1 = sol.combinationSum2(candidates1, target1);
    
    cout << "Combinations that sum to " << target1 << ":\n";
    for (const auto& comb : result1) {
        cout << "[ ";
        for (int num : comb) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    vector<int> candidates2 = {2, 5, 2, 1, 2};
    int target2 = 5;
    vector<vector<int>> result2 = sol.combinationSum2(candidates2, target2);
    
    cout << "Combinations that sum to " << target2 << ":\n";
    for (const auto& comb : result2) {
        cout << "[ ";
        for (int num : comb) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}
```

### Summary
- **Sorting** the candidates array simplifies handling duplicates.
- **Backtracking** is used to explore all possible combinations.
- **Skipping duplicates** ensures unique combinations.
- This approach ensures all unique combinations that sum up to the target are found without duplicates.

Feel free to ask if you have any questions or need further clarifications!
