class Solution {
public:
    int countSetBits(int i){
        int count = 0;
        while(i){
            count += i & 1;
            i >>= 1;
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int> result;
        for(int i=0; i<=n; i++){
            result.push_back(countSetBits(i));
        }
        return result;
    }
};