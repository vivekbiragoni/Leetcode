//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    void rearrange(vector<int> &arr) {
        // code here
        vector<int> positive, negative;
        
        // Separate positive and negative numbers
        for (int num : arr) {
            if (num >= 0)
                positive.push_back(num);
            else
                negative.push_back(num);
        }
        
        int i = 0, pos_idx = 0, neg_idx = 0;
        bool turn_positive = true;  // Alternate flag
        
        // Merge positive and negative arrays alternately
        while (pos_idx < positive.size() && neg_idx < negative.size()) {
            if (turn_positive) {
                arr[i++] = positive[pos_idx++];
            } else {
                arr[i++] = negative[neg_idx++];
            }
            turn_positive = !turn_positive;
        }
        
        // Add the remaining positive elements if any
        while (pos_idx < positive.size()) {
            arr[i++] = positive[pos_idx++];
        }
        
        // Add the remaining negative elements if any
        while (neg_idx < negative.size()) {
            arr[i++] = negative[neg_idx++];
        }
    
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends