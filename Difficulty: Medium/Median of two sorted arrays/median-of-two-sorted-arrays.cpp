//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

//Position this line where user code will be pasted.
class Solution {
  public:
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2) {
        // code here
        vector<int> res;
        int s1 = arr1.size();
        int s2 = arr2.size();
        int j = 0, i = 0; 
        for(; i < s1 && j < s2; ){
            if(arr1[i]<arr2[j]){
                res.push_back(arr1[i]);
                i++;
            } 
            else if(arr1[i]>arr2[j]){
                res.push_back(arr2[j]);
                j++;
            }else{
                res.push_back(arr1[i]);
                res.push_back(arr2[j]);
                i++;
                j++;
            }
        }
        while(i<s1){
            res.push_back(arr1[i]);
            i++;
        }
        while(j<s2){
            res.push_back(arr2[j]);
            j++;
        }
        int sz = res.size();
        if(sz%2==0){
            int mid = 0 + (sz-0)/2;
            return res[mid]+res[mid-1];
        }else if(sz%2==1){
            int mid = 0 + (sz-0)/2;
            return res[mid];
        }
    }
};

//{ Driver Code Starts.
//Back-end complete function template in C++

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, brr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            brr.push_back(number2);
        }
        Solution ob;
        int res = ob.SumofMiddleElements(arr, brr);
        cout << res << endl;
    }
}
// } Driver Code Ends