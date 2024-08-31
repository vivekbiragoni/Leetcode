class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        if(n==1) return 1;
        vector<int> dp;
        for(auto num: nums){
            auto it = lower_bound(dp.begin(), dp.end(), num);
            if(it==dp.end()){
                dp.push_back(num);
            }else{
                *it = num;
            }
        }
        return dp.size();
    }
};