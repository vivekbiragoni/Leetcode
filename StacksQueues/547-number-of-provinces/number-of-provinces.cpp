class Solution {
public:
    void dfs(int node, vector<bool>& visited,
             const vector<vector<int>> isConnected) {
                visited[node] = true;
                for(int neighbor = 0; neighbor < isConnected.size(); neighbor++){
                    if(isConnected[node][neighbor] == 1 && !visited[neighbor]){
                        dfs(neighbor, visited, isConnected);
                    }
                }
             }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);

        int componentCount = 0;

        for(int i = 0; i < n; i++){
            if(!visited[i]){
                dfs(i, visited, isConnected);
                componentCount++;
            }
        }
        return componentCount;
    }
};