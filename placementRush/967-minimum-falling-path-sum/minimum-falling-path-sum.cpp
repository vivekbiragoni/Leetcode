class Solution {
public:
    int helper(vector<vector<int>>& matrix, int i, int j,
               vector<vector<int>>& dp) {
        int m = matrix.size();
        int n = matrix[0].size();

        if (i == 0)
            return matrix[0][j];
        if (j >= n || j < 0)
            return 1e9;

        if (dp[i][j] != -1)
            return dp[i][j];

        // int s = 0, ld = 0, rd = 0;
        int s = matrix[i][j] + helper(matrix, i - 1, j, dp);
        int ld =
            matrix[i][j] + (j > 0 ? helper(matrix, i - 1, j - 1, dp) : 1e9);
        int rd =
            matrix[i][j] + (j < n - 1 ? helper(matrix, i - 1, j + 1, dp) : 1e9);

        return dp[i][j] = min(s, min(ld, rd));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        // int result = 1e9;
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // for (int i = 0; i < n; i++) {
        //     result = min(helper(matrix, m - 1, i, dp), result);
        // }
        // return result;

        int dp[m][n]; // tabulate init
        for (int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j]; // base case
        }
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int s = INT_MAX, ld = INT_MAX, rd = INT_MAX;
                s = matrix[i][j] + dp[i - 1][j];

                if (j > 0) {
                    ld = matrix[i][j] + dp[i - 1][j - 1];
                }

                if (j < n - 1) {
                    rd = matrix[i][j] + dp[i - 1][j + 1];
                }
                dp[i][j] = min(s, min(ld, rd));
            }
        }
        int mini = INT_MAX;
        for(int j = 0; j < n; j++){
            mini = min(dp[m-1][j], mini);
        }
        return mini;
    }
};