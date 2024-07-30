class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxLen = 0;
        int sz = nums.size();
        for(int i = 0; i < sz; i++){
            if(i > maxLen) return false; // havent reached that index
            maxLen =  max(maxLen, i + nums[i]);
        }
        return true;
    }
};