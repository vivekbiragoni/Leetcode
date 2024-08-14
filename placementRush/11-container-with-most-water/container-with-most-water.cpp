class Solution {
public:
    int maxArea(vector<int>& nums) {
        int n = nums.size();
        int left = 0; 
        int right = n-1;
        int maxi = -1e9;
        while(left<right){
            int smaller = min(nums[left], nums[right]);
            int range = right - left;
            maxi = max(maxi, smaller*range);
            if(smaller == nums[left]){
                left++;
            }else{
                right--;
            }
        }
        return maxi;
    }
};