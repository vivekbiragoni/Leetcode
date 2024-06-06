//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
private:
    void generateHelper(int N, string current_str, vector<string>& result) {
    // Base case: If length of current string equals N, add it to the result
    if (current_str.length() == N) {
        result.push_back(current_str);
        return;
    }

    // Append '0' to the current string
    generateHelper(N, current_str + '0', result);

    // If last character is '0', append '1'
    if (current_str.empty() || current_str.back() == '0') {
        generateHelper(N, current_str + '1', result);
    }
}

public:
    vector<string> generateBinaryStrings(int num){
        
        vector<string> result;
        generateHelper(num, "", result);

        return result;
        
        
    }
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        
        vector<string> v = obj.generateBinaryStrings(n);
        for(auto it:v) cout<<it<<" ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends