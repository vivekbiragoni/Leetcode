class Solution {
private:
    bool bfs(int start, vector<int>& color, vector<vector<int>>& graph) {

        queue<int> q;
        q.push(start);
        color[start] = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : graph[node]) {
                if (color[neighbor] == -1) { // If not colored
                    color[neighbor] = 1 - color[node]; // Alternate color
                    q.push(neighbor);
                } else if (color[neighbor] == color[node]) { // If same color as node
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();

        // int color[V];
        vector<int> color(V, -1);
        for (int i = 0; i < V; i++) {
            if (color[i] == -1) { // If not colored, start BFS
                if (!bfs(i, color, graph)) {
                    return false;
                }
            }
        }
        return true;
    }
};