class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<int>>& board, int delrow[], int delcol[]) {
        vis[row][col] = 1;
        int n = board.size();
        int m = board[0].size();
        
        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && board[nrow][ncol] == 1) {
                dfs(nrow, ncol, vis, board, delrow, delcol);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& board) {
         int n = board.size();
        if (n == 0) return 0; // Handle edge case for empty board
        int m = board[0].size();
        
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        vector<vector<int>> vis(n, vector<int>(m, 0)); // 0 for unvisited, 1 for visited
        
        // Traverse first and last rows
        for (int j = 0; j < m; j++) {
            if (!vis[0][j] && board[0][j] == 1) {
                dfs(0, j, vis, board, delrow, delcol);
            }
            if (!vis[n - 1][j] && board[n - 1][j] == 1) {
                dfs(n - 1, j, vis, board, delrow, delcol);
            }
        }
        
        // Traverse first and last columns
        for (int i = 0; i < n; i++) {
            if (!vis[i][0] && board[i][0] == 1) {
                dfs(i, 0, vis, board, delrow, delcol);
            }
            if (!vis[i][m - 1] && board[i][m - 1] == 1) {
                dfs(i, m - 1, vis, board, delrow, delcol);
            }
        }
        
        int capturedCount = 0; // Counter for captured cells
        
        // Update board based on visited cells and count captured cells
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 1 && !vis[i][j]) {
                    board[i][j] = 0; // Flip 'O' to 'X' if it's not visited
                    capturedCount++; // Increment the counter for each captured cell
                }
            }
        }
        
        // Restore boundary-connected 'O's back to 'O'
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j]) {
                    board[i][j] = 1; // Restore cells marked as visited
                }
            }
        }
        
        return capturedCount; // Return the number of captured cells
    }
};