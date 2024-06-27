class Solution {
public:
    int numberOfSubarraysHelper(vector<int>& nums, int k) {
        int left = 0;
        int right = 0; 
        int sum = 0;
        int cont = 0;
        while(right < nums.size()){
            sum += nums[right]%2;

            while(sum>k && left <= right){
                sum -= nums[left]%2;
                left++;
            }
            cont += (right - left + 1);
            right++;
        }
        return cont;
    }



    int numberOfSubarrays(vector<int>& nums, int k) {
        return numberOfSubarraysHelper(nums, k) - numberOfSubarraysHelper(nums, k-1);
    }
};