class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<1) return false;
        if ((n & (n-1)) == 0){
            return true;
        }
        return false;
    }
};