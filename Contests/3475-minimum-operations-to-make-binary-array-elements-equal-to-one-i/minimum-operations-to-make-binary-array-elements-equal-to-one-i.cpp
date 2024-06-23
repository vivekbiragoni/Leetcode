class Solution {
public:
    int minOperations(vector<int>& nums) {
        size_t n = nums.size();
        int ops = 0;
        for (int i = 0; i <= n - 3; i++) {
            if (nums[i] == 1)
                continue;

            if (i + 1 < n && i + 2 < n) {
                nums[i] ^= 1;
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
                ops+=1;
            }
        }
        for(int num : nums ){
            if(num!=1){
                return -1;
            };
            
        }
        return ops;
    }
};