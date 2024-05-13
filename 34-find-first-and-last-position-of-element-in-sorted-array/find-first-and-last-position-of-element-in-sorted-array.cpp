#include <algorithm>
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()){
            return{ -1, -1};
        }
        int lb = lower_bound(nums.begin(), nums.end(), target)-nums.begin();
        int ub = upper_bound(nums.begin(), nums.end(), target)-nums.begin();
        if (lb < nums.size() && nums[lb] == target && ub - 1 < nums.size()) {
            return {lb, ub - 1};
        } else {
            return {-1, -1};
        }
    }
};