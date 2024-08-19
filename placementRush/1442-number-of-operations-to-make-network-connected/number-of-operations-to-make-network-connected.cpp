class DisjointSet{
    public:
    vector<int> size, parent;

    DisjointSet(int n){
        size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i= 0; i< n; i++){
            parent[i]=i;
        }
    }
    int find(int node){
        if(node==parent[node]) return node;
        return parent[node] = find(parent[node]);
    }
    void unionBySize(int u, int v){
        int ulp_u = find(u);
        int ulp_v = find(v);

        if(ulp_v==ulp_u)return;
        if(size[ulp_u]>size[ulp_v]){
            parent[ulp_v] = ulp_u;
            size[ulp_u]+=size[ulp_v];
        }else{
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int contExtras = 0;
        for(auto it: connections){
            int u = it[0];
            int v = it[1];
            if(ds.find(u)==ds.find(v)){
                contExtras++;
            }else{
                ds.unionBySize(u,v);
            }
        }
        int contC = 0;
        for(int i = 0; i< n; i++){
            if(ds.parent[i]==i) contC++;
        }
        int ans = contC - 1;
        if(contExtras>=ans) return ans;
        else return -1;
    }
};