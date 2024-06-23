class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        vector<pair<int, int>> indices;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    indices.push_back({i, j});
                }
            }
        }

        int minX = indices[0].first;
        int minY = indices[0].second;
        int maxX = indices[0].first;
        int maxY = indices[0].second;

        
        for (const auto& p : indices) {
            if (p.first < minX) {
                minX = p.first;
            }
            if (p.first > maxX) {
                maxX = p.first;
            }
            if (p.second < minY) {
                minY = p.second;
            }
            if (p.second > maxY) {
                maxY = p.second;
            }
        }

        int width = maxX - minX+1;
        int height =maxY - minY+1;
        return width * height;
    }
};