class DisjointSet{
    public:
    vector<int> par, size;
    DisjointSet(int n){
        par.resize(n+1);
        for(int i = 0; i< n; i++){
            par[i]=i;
        }
        size.resize(n+1, 1);
    }
    int find(int u){
        if(u==par[u]) return u;
        return par[u]=find(par[u]);
    }
    void unionBySize(int u, int v){
        int ulp_u = find(u);
        int ulp_v = find(v);
        if(ulp_u==ulp_v) return ;
        if(size[ulp_u]>size[ulp_v]){
            par[ulp_v]=ulp_u;
            size[ulp_u]+= size[ulp_v];
        }else{
            par[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        DisjointSet ds(20002);
        for (auto& stone : stones) {
        int row = stone[0];
        int col = stone[1] +10001;
        ds.unionBySize(row, col);
    }


    unordered_set<int> uniqueParents;
    for (auto& stone : stones) {
        uniqueParents.insert(ds.find(stone[0]));
    }
    return n - uniqueParents.size();
    }
};