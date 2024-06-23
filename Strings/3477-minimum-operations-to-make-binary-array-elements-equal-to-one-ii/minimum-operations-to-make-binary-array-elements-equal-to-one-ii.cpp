class Solution {
public:
    int minOperations(vector<int>& nums) {
        size_t n = nums.size();
        int ops = 0;
        bool toggle = false;

        for (int i = 0; i < n; i++) {
            if ((nums[i] == 0 && !toggle)|| (nums[i]==1 && toggle)) {
                ops++;
                toggle = !toggle;
            }
        }
        return ops;
    }
};