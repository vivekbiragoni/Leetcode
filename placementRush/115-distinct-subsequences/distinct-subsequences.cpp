class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();

        vector<vector<double>> dp(m + 1, vector<double>(n + 1, 0));

        // base case
        for (int i = 0; i < m; i++)
            dp[i][0] = 1;


        // changing params
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {

                // recursion
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }

        }
        return (int)dp[m][n];
    }
};