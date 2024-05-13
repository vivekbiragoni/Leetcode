class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int element;
        for (int i = 0; i < nums.size(); i++) {
            if (count == 0) {
                count = 1;
                element = nums[i];
            } else if (element == nums[i]) {
                count++;
            } else {
                count--;
            }
        }
        // int cnt = 0;
        // for(int i = 0; i< nums.size(); i++){
        //     if(nums[i]==element) cnt++;
        // }
        // if(cnt>nums.size()/2)
        return element;
        // else
        //     return -1;
    }
};