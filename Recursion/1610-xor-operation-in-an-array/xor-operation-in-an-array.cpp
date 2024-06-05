class Solution {
public:
    int xorOperation(int n, int start) {
        // vector<int> nums;
        int Xor = start;
        for(size_t i = 1; i<n; i++){
            Xor ^= (start+2*i);
        }
        return Xor;
    }
};