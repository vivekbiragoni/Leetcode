class Solution {
public:
    int solve(vector<int>& nums,vector<vector<int>>&dp, int ind, int prev_ind, int n){
        
        if(ind==n) return 0;

        if(dp[ind][prev_ind+1]!=-1) return dp[ind][prev_ind+1];

        int notake = 0 + solve(nums, dp, ind+1, prev_ind, n);

        int take = 0;
        if(prev_ind==-1 || nums[ind]>nums[prev_ind]){
            take = 1 + solve(nums, dp, ind+1, ind, n);
        }

        return dp[ind][prev_ind+1] = max(take, notake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return solve(nums, dp, 0,-1,n);
    }
};