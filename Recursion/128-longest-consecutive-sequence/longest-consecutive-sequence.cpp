class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int maxConsecutive = 1;
        int sequence = 1;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1])
                continue;
            else if (nums[i] == nums[i - 1] + 1) {
                sequence++;
            } else {
                maxConsecutive = max(maxConsecutive, sequence);
                sequence = 1;
            }
        }
        maxConsecutive = max(maxConsecutive, sequence);
        return maxConsecutive;
    }
};