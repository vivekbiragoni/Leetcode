class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int col0 = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0 ; j < m ; j++){
                if(matrix[i][j]==0){
                    // mark the ith row
                    matrix[i][0] = 0;
                    if(j!=0){
                        matrix[0][j]=0;
                    }
                    else{
                        col0 = 0;
                    }
                }
            }
        }
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(matrix[i][j]!=0){
                    if(matrix[i][0]==0 || matrix[0][j]==0){
                        matrix[i][j]=0;
                    }
                }
            }
        }
        if(matrix[0][0]==0){
            for(int i = 0; i < m; i++){
                matrix[0][i]=0;
            }
        }
        if(col0==0){
            for(int j = 0; j < n; j++){
                matrix[j][0]=0;
            }
        }
        
    }
};