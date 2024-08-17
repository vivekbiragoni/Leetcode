class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();

        int totsum = 0, leftsum = 0;

        for(int num : nums){
            totsum += num;
        }
        for(int i = 0; i< n; i++){
            if(leftsum == totsum-nums[i]-leftsum){
                return i;
            }
            leftsum += nums[i];
        }
        return -1;
    }
};