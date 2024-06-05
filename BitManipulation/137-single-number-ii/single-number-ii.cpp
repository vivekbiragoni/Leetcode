class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int bitcount[32] = {0};

        for(int num : nums){
            for(int i = 0; i < 32; ++i){
                bitcount[i] += (num >> i) & 1;
            }
        }

        int result = 0;
        for(int i = 0; i < 32; ++i){
            if(bitcount[i] % 3 != 0){
                result |= (1<<i);
            }
        }
        return result;
    }
};