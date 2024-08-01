//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int f(vector<vector<int>>&points, int day, int last,vector<vector<int>> &dp){
        if(day == 0){
            int maxi = 0;
            for(int task=0; task<3; task++){
                if(last!=task){
                    maxi = max(maxi, points[0][task]);
                }
            }
            return maxi;
        }
        if(dp[day][last]!=-1) return dp[day][last];
        int maxi = 0;
        for(int task = 0; task < 3; task++){
            if(task!=last){
                int point = points[day][task] + f(points, day-1, task, dp);
                maxi = max(maxi, point);
            }
        }
        return dp[day][last] =  maxi;
        
    }
    int maximumPoints(vector<vector<int>>& arr, int n) {
        // Code here
        vector<vector<int>> dp(n, vector<int>(4,-1));
        return f(arr, n-1, 3, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            arr.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends