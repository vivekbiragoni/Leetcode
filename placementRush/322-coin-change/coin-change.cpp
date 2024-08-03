class Solution {
public:
    int f(int ind, int t,vector<int>& coins, vector<vector<int>> &dp ){
        if(ind==0){
            if(t%coins[0]==0){
                return t/coins[0];
            }else{
                return 1e9;
            }
        }
        if(dp[ind][t]!=-1) return dp[ind][t];

        int nottake = 0 + f(ind-1, t, coins, dp);
        int take = 1e9;
        if(coins[ind]<=t){
            take = 1 + f(ind, t-coins[ind], coins, dp);
        }

        return dp[ind][t] = min(take, nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int ind = coins.size();

        vector<vector<int>> dp(ind, vector<int>(amount+1, -1));

        int ans = f(ind-1,amount, coins, dp);
        if(ans>=1e9) return -1;
        else{
            return ans;
        }
    }
};