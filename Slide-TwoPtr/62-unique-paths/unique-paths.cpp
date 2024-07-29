class Solution {

public:
    int uniquePaths(int m, int n) {
        int N = m + n - 2;
        int r = min(m-1, n-1);
        double result = 1;
        for(int i = 1; i <= r; i++){
            result = result * (N-r+i)/i;
        }
        return (int)result;
    }
};