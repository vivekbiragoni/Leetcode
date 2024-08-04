class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();

        vector<double> prev(n+1, 0), cur(n+1, 0);

        // base case
        prev[0] = cur[0] = 1;


        // changing params
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {

                // recursion
                if (s[i - 1] == t[j - 1]) {
                    cur[j] = prev[j - 1] + prev[j];
                } else {
                    cur[j] = prev[j];
                }
            }
            prev = cur;
        }
        return (int)prev[n];
    }
};