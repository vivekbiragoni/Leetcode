class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int myxor = 0;
        for(int i = 0; i < nums.size(); i++){
            myxor ^= nums[i];
        }
        return myxor;
    }
};