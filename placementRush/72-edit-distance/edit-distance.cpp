class Solution {
public:
    int help(string s1, string s2, int i , int j,  vector<vector<int>> &dp){

        //base
        if(i==0) return j;  //insert in s1
        if(j==0) return i; // delete in s1

        //mem check
        if(dp[i][j]!=-1) return dp[i][j];

        //all possibilities
        if(s1[i-1]==s2[j-1]) return dp[i][j] =  0 + help(s1, s2, i-1, j-1, dp);
        int ins = 1 + help(s1, s2, i, j-1, dp);
        int del = 1 + help(s1, s2, i-1, j, dp);
        int rep = 1 + help(s1, s2, i-1, j-1, dp);

        return dp[i][j] = min(ins, min(del, rep));
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return help(word1, word2, n, m, dp);
    }
};