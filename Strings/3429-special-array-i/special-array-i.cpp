class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        if ((nums[0] % 2 == 1 && nums[1] % 2 == 0) ||
            (nums[0] % 2 == 0 && nums[1] % 2 == 1)) {
        } else {
            return false;
        }

        if ((nums[n - 1] % 2 == 1 && nums[n - 2] % 2 == 0) ||
            (nums[n - 1] % 2 == 0 && nums[n - 2] % 2 == 1)) {
        } else {
            return false;
        }
        for (int j = 1; j < n - 1; j++) {
            if ((nums[j] % 2 == 1 && nums[j + 1] % 2 == 0) ||
                (nums[j] % 2 == 0 && nums[j + 1] % 2 == 1)) {

            } else {
                return false;
            }
        }
        return true;
    }
};