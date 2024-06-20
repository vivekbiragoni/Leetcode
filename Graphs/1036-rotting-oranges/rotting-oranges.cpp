class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> rotten;
        int freshOranges = 0;

        // enquiring the grid
        for(int i = 0; i < m; i++){
            for(int j =0; j < n ; j++){
                if(grid[i][j]==2){
                    rotten.push({i,j});
                }else if(grid[i][j]==1){
                    freshOranges++;
                }
            }
        }

        // directions up, down, left, right
        vector<pair<int, int>> directions = {{-1,0}, {1,0},{0,-1},{0,1}};

        int minutes = 0;

        while(!rotten.empty() && freshOranges > 0){
            int sz = rotten.size();

            for(int k = 0; k < sz; k++){
                int x = rotten.front().first;
                int y = rotten.front().second;
                rotten.pop();

                for(auto &dir : directions){
                    int nx = x + dir.first;
                    int ny = y + dir.second;

                    if(nx>=0 && nx < m && ny>=0 && ny < n && grid[nx][ny]==1){
                        grid[nx][ny] = 2;
                        rotten.push({nx, ny});
                        freshOranges--;
                    }
                }
            }
            minutes++;
        }

        if(freshOranges> 0){
            return -1;
        }else{
            return minutes;
        }

         

    }
};