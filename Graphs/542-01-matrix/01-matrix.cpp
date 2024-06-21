class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        queue<pair<int, int>> q;


        // enque 0 cells and mark their dist as 0
        for(int i = 0; i < m ; i++){
            for(int j = 0; j< n; j++){
                if(mat[i][j]==0){
                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        }


        vector<pair<int, int>> directions = {{-1,0},{0,1},{1,0},{0,-1}};


        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();


            for(auto & direction : directions){
                int nx = x + direction.first;
                int ny = y + direction.second;

                if(nx>=0 && ny >= 0 &&  nx < m && ny < n && dist[nx][ny] > dist[x][y]+1 ){
                    dist[nx][ny] = dist[x][y]+1;
                    q.push({nx, ny});
                }
            }
        }
        return dist;
    }
};