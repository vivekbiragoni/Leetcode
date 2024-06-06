class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos, neg;
        for(size_t i = 0; i < nums.size(); i++){
            nums[i] >= 0 ? pos.push_back(nums[i]) : neg.push_back(nums[i]);
        }
        vector<int> ans;
        for(size_t i = 0; i < pos.size(); i++){
            ans.push_back(pos[i]);
            ans.push_back(neg[i]);
        }
        return ans;
    }
};