class Solution {
private:
    void backTrack(vector<int>& nums, vector<vector<int>> &result,
                   vector<int> subset, int start) {
        result.push_back(subset);

        for (int i = start; i < nums.size(); ++i) {
            if (i > start && nums[i] == nums[i - 1])
                continue;

            subset.push_back(nums[i]); // Include nums[i] in the subset
            backTrack(nums, result, subset, i + 1); // Recurse with next index
            subset.pop_back(); // Backtrack: remove nums[i] from the subset
        }
    }


public:
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> subset;
    sort(nums.begin(), nums.end());
    backTrack(nums, result, subset, 0);
    return result;
}
}
;