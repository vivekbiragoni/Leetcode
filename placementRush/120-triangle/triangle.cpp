class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();

        vector<vector<int>> dp(m, vector<int>(m, 1e9));

        dp[0][0] = triangle[0][0];

        for (int i = 1; i < m; i++) {
            for (int j = 0; j < triangle[i].size(); j++) {
                if (j < triangle[i - 1].size()) {
                    dp[i][j] = min(dp[i][j], triangle[i][j] + dp[i - 1][j]);
                }
                if (j > 0) {
                    dp[i][j] = min(dp[i][j], triangle[i][j] + dp[i - 1][j - 1]);
                }
            }
        }
        int mini = 1e9;
        for (int j = 0; j < triangle[m - 1].size(); j++) {
            mini = min(dp[m - 1][j], mini);
        }
        return mini;
    }
};