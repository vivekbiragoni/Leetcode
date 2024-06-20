class Solution {
public:
    void dfs(vector<vector<int>>&image, int r, int c, int newColor, int originalColor, int m, int n){
        if(r<0||c<0|| r >= m || c >= n ||   image[r][c]!=originalColor) return;

        image[r][c] = newColor;
        

        dfs(image, r, c-1, newColor, originalColor, m, n);
        dfs(image, r-1, c, newColor, originalColor, m, n );
        dfs(image, r+1, c, newColor, originalColor, m, n );
        dfs(image, r, c+1, newColor, originalColor, m, n );
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        if(image[sr][sc]==color) return image;

        int m = image.size();
        int n = image[0].size();

        int originalColor = image[sr][sc];
        dfs(image, sr, sc, color, originalColor, m, n);

        return image;
    }
};