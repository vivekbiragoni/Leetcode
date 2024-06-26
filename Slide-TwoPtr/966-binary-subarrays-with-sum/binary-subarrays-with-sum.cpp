class Solution {
public:
    int numSubarraysWithSumHelper(vector<int>& nums, int goal) {
        if(goal<0) return 0;
        int  left = 0;
        int sum = 0;
        int cont = 0;
        int right = 0;
        while(right < nums.size()){
            sum += nums[right];
            while(sum>goal && left <= right){
                sum -= nums[left];
                left++;
            }
            cont += (right-left+1);
            right++;
        }
        return cont;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return numSubarraysWithSumHelper(nums, goal) -  numSubarraysWithSumHelper(nums, goal-1);
    }
};