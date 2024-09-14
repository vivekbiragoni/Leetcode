class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int me = *max_element(nums.begin(), nums.end());
        int longest = 0, current = 0;
        for(auto num: nums){
            if(num==me){
                current++;
                longest = max(longest, current);
            }else{
                current = 0;
            }
        }
        return longest;
    }
};