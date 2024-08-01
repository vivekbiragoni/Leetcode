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
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(m - 1, n - 1, dp, grid);
    }
};