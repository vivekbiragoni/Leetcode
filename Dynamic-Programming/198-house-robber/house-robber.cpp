class Solution {
public:
// just the recursion
    int rob(vector<int>& arr) {
        // int mxRobbery = helper(nums, nums.size()-1);
        // return mxRobbery;
        int n = arr.size();
        long long int prev = arr[0];
        long long int prev2 = 0;

        for (int i = 1; i < n; i++) {
            long long int pick = arr[i];
            if (i > 1)
                pick += prev2;
            int long long nonPick = 0 + prev;

            long long int cur_i = max(pick, nonPick);
            prev2 = prev;
            prev = cur_i;
        }
        return prev;
    
    }
    // int helper(vector<int>& nums, int index){
    //     // base case
        
    //     if(index<0) return 0;
    //     if(index==0) return nums[index]; //This case is reached, only when the index ==1 is not reached, so just pick it

    //     // pick
    //     int pick = nums[index] + helper(nums, index-2);
    //     // not-pick
    //     int not_pick = 0       + helper(nums, index-1);
    //     return max(pick, not_pick);
    // }

    // int helper(vector<int>& nums, int index){
    //     // base case
    //     int n = nums.size();
    //     vector<int> dp(n+1, -1);
    //     if(index<0) return 0;
    //     if(index==0) return nums[index]; //This case is reached, only when the index ==1 is not reached, so just pick it
        
        
    //     if(dp[index]!= -1) return dp[index];
        
    //     // pick
    //     int pick = nums[index] + helper(nums, index-2);
        
    //     // not-pick
    //     int not_pick = 0       + helper(nums, index-1);
        
    //     return dp[index] = max(pick, not_pick);
    // }
};