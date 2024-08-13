class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int, pair<int, int>>> q;
        int n = grid.size();
        int m = grid[0].size();
        if (n - 1 == 0 && m - 1 == 0 && grid[0][0]==0)
            return 1;
        if(grid[0][0]==1 ||grid[n-1][m-1]==1) return -1;
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 1;
        q.push({1, {0, 0}});

        vector<pair<int, int>> directions = {{-1, -1}, {-1, 0}, {-1, 1},
                                             {0, 1},   {1, 1},  {1, 0},
                                             {1, -1},  {0, -1}};

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int row = it.second.first;
            int col = it.second.second;

            for (auto direction : directions) {
                int nrow = direction.first + row;
                int ncol = direction.second + col;
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    grid[nrow][ncol] == 0 && dis + 1 < dist[nrow][ncol]) {
                    dist[nrow][ncol] = 1 + dis;
                    if (nrow == n - 1 && ncol == m - 1)
                        return dis + 1;
                    q.push({1 + dis, {nrow, ncol}});
                }
            }
        }
        return -1;
    }
};