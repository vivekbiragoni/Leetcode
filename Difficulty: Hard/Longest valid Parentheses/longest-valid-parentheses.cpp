//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxLength(string& s) {
        // code here
        int maxLength = 0;
        stack<int> st;
        st.push(-1);  // Initialize the stack with -1 to handle base cases.

        // Traverse the string
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                // Push the index of the '(' onto the stack
                st.push(i);
            } else {
                // Pop the top element since we have a closing ')'
                st.pop();

                // If stack becomes empty, push the current index as base for next valid substring
                if (st.empty()) {
                    st.push(i);
                } else {
                    // Calculate the length of the valid substring
                    maxLength = max(maxLength, i - st.top());
                }
            }
        }
        return maxLength;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.maxLength(S) << "\n";
    }
    return 0;
}
// } Driver Code Ends