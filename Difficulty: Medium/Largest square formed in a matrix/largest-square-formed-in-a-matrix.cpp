//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int solve(int i, int j, vector<vector<int>>&mat, int &maxi,vector<vector<int>> &dp){
        if(i>=mat.size() || j>=mat[0].size()) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int right = solve(i+1, j, mat, maxi, dp);
        int diagonal = solve(i+1, j+1, mat, maxi, dp);
        int down = solve(i, j+1, mat, maxi,dp);
        
        if(mat[i][j]==1){
            int ans = 1 + min(right,min(diagonal, down));
            maxi = max(ans, maxi);
            return dp[i][j] = ans;
        }else{
            return dp[i][j] =0;
        }
    }
    int maxSquare(int n, int m, vector<vector<int>> mat) {
        // code here
        int maxi = 0;
        vector<vector<int>> dp(n, vector<int>(m,-1));
        solve(0, 0, mat, maxi, dp);
        return maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for (int i = 0; i < n * m; i++)
            cin >> mat[i / m][i % m];

        Solution ob;
        cout << ob.maxSquare(n, m, mat) << "\n";
    }
    return 0;
}
// } Driver Code Ends