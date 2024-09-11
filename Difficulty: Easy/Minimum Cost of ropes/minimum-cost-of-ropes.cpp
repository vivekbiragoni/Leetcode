//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(vector<long long>& arr) {
        // Your code here
        priority_queue<long long, vector<long long>, greater<long long>> minHeap(arr.begin(), arr.end());
        
        long long ans = 0;
        while (minHeap.size() > 1) {

            long long first = minHeap.top(); minHeap.pop();
            long long second = minHeap.top(); minHeap.pop();
            
            long long cost = first + second;
            ans += cost;
            
            minHeap.push(cost);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        long long num;
        vector<long long> a;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(a) << endl;
    }
    return 0;
}

// } Driver Code Ends