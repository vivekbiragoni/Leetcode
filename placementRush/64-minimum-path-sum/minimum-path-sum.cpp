class Solution {
public:
    int helper(int i, int j, vector<vector<int>>& dp, vector<vector<int>> &grid) {

        if (i == 0 && j == 0)
            return grid[0][0];  //reached the base case

        if (i < 0 || j < 0)
            return INT_MAX;  //outofbounds

        if (dp[i][j] != -1)
            return dp[i][j]; //already computed the results for the node

        int up = INT_MAX, left = INT_MAX;  
        if (i > 0) {
            up = grid[i][j] + helper(i - 1, j, dp, grid);
        }
        if (j > 0) {
            left = grid[i][j] + helper(i, j - 1, dp, grid);
        }

        return dp[i][j] = min(up, left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        int dp[m][n];
        for(int i = 0; i < m ; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0) dp[0][0] = grid[0][0];
                else{
                    int up = INT_MAX, left = INT_MAX;
                    if(i>0){
                        up = grid[i][j] + dp[i-1][j];
                    }
                    if(j>0){
                        left = grid[i][j] + dp[i][j-1];
                    }
                    dp[i][j] =  min(up, left);
                }
            }
        }
        return dp[m-1][n-1];
        
    }
};