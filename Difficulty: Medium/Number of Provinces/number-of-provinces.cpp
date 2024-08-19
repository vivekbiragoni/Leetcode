//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


class DisjointSet{
    public:
        vector<int> rank, parent, size;
        DisjointSet(int n){
            parent.resize(n+1);
            rank.resize(n+1, 0);
            size.resize(n+1);
            for(int i =0; i< n; i++){
                parent[i] =i;
                size[i]=1;
            }
        }
        int find(int node){
            if(node==parent[node]) return node;
            return parent[node] = find(parent[node]);
        }
        void unionByRank(int u, int v){
            int ulp_u = find(u);
            int ulp_v = find(v);
            if(ulp_u==ulp_v) return;
            
            if(rank[ulp_u]<rank[ulp_v]){
                parent[ulp_u] = ulp_v;
            }else if(rank[ulp_u]>rank[ulp_v]){
                parent[ulp_v] = ulp_u;
            }else{
                parent[ulp_u] = ulp_v;
                rank[ulp_v]++;
            }
        }
        void unionBySize(int u, int v){
            int ulp_u = find(u);
            int ulp_v = find(v);
            if(ulp_u==ulp_v) return;
            
            if(size[ulp_u]>size[ulp_v]){
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
                
            }else{
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
        }
};






// } Driver Code Ends
class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        DisjointSet ds(V);
        
        for(int i = 0; i< V; i++){
            for(int j = 0; j<V; j++){
                if(adj[i][j]==1){
                    ds.unionBySize(i, j);
                }
            }
        }
        int cont=0;
        for(int i = 0; i<V; i++){if(ds.parent[i]==i){
                cont++;
            }
        }
        return cont;
    
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends