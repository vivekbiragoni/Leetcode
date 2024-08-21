class Solution {
public:
    int minturns(int start, int end, const string& s, vector<vector<int>>& dp) {
        if (start > end)
            return 0;

        if (dp[start][end] != -1)
            return dp[start][end];
        int minTurns = 1 + minturns(start + 1, end, s, dp);
        for (int k = start + 1; k <= end; k++) {
            if (s[k] == s[start]) {
                int turnswithMatch = minturns(start, k - 1, s, dp) + minturns(k+1, end, s, dp);
                minTurns = min(minTurns, turnswithMatch);
            }
        }
        return dp[start][end] = minTurns;
    }
    string removeDuplicates(string&s){
        string uniquechars;
        int i = 0;
        while(i<s.length()){
            char currentchar = s[i];
            uniquechars += currentchar;
            while(i<s.length() && s[i]==currentchar){
                i++;
            }
        }
        return uniquechars;
    }
    int strangePrinter(string s) {
        s = removeDuplicates(s);
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return minturns(0, n - 1, s, dp);
    }
};