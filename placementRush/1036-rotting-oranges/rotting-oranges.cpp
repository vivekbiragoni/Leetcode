class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(n==0||m==0) return 0;
        int day = 0, tot = 0, cont = 0; 
        queue<pair<int,int>> q;
        for(int i =0; i< n; i++){
            for(int j = 0; j< m; j++){
                if(grid[i][j]!=0) tot++;
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        vector<pair<int,int>> directions = {{0,1},{1,0},{-1,0}, {0,-1}};
        while(!q.empty()){
            int k = q.size();
            cont+=k;
            while(k--){
                int x = q.front().first, y = q.front().second;
                q.pop();
                for(auto direction: directions){
                    int nx = x + direction.first, ny = y + direction.second;

                    if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]==1){
                        grid[nx][ny]=2;
                        q.push({nx, ny});
                    }else{
                        continue;
                    }
                }
            }
            if(!q.empty()) day++;
        }
        return tot==cont ? day : -1;
    }
};