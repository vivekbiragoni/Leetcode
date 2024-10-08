//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    vector<int> sieveOfEratosthenes(int N)
    {
        // Write Your Code here
        vector<bool> prime(N+1, true);
        vector<int> ans;
        for(int p = 2; p*p<=N; p++){
            if(prime[p]==true){
                
                for(int i = p*p; i<=N; i+=p){
                    prime[i] = false;
                }
            }
        }
        for(int i = 2; i<=N; i++){
            if(prime[i]==true){
                ans.emplace_back(i);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        vector<int> primes  = ob.sieveOfEratosthenes(N);
        for(auto prime : primes) {
            cout<< prime <<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends