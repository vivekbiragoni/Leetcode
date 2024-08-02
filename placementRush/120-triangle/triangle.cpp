class Solution {
public:
    int helper(vector<vector<int>>& triangle, vector<vector<int>>& dp, int i, int j){
        int m = triangle.size();


        if(i == 0 && j == 0) return triangle[0][0]; //base
        if(i<0 || j < 0 || j>=triangle[i].size() ) return 1e9; //bounds

        int up = 1e9, left = 1e9; //init

        if(dp[i][j]!= -1) return dp[i][j]; //memo

        up = triangle[i][j] +  helper(triangle, dp, i-1, j);//go up
        left = triangle[i][j] + helper(triangle, dp, i-1, j-1);// go left
        return dp[i][j] =  min(up, left);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();

        vector<vector<int>> dp(m, vector<int>(m, -1));
        int mini = 1e9;
        for(int j = 0; j < triangle[m-1].size(); j++){
            mini = min(mini, helper(triangle, dp, m-1, j));
        }
        return mini;
    }
};