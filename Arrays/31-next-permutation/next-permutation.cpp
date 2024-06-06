
// ### Applying the Algorithm:

// For an array `nums = [1, 3, 2]`:

// 1. Find `k` such that `nums[k] < nums[k+1]`. Here, `k = 0` (nums[0] = 1, nums[1] = 3).
// 2. Find `l` such that `nums[k] < nums[l]`. Here, `l = 2` (nums[2] = 2).
// 3. Swap `nums[k]` with `nums[l]`. The array becomes [2, 3, 1].
// 4. Reverse the sequence from `nums[k+1]` to the end. The array becomes [2, 1, 3].


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int k = -1;
        
        // Step 1: Find the largest index k such that nums[k] < nums[k+1]
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                k = i;
                break;
            }
        }
        // If no such index exists, the permutation is the last permutation
        if (k == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        // Step 2: Find the largest index l greater than k such that nums[k] < nums[l]
        int l = -1;
        for (int i = n - 1; i > k; --i) {
            if (nums[i] > nums[k]) {
                l = i;
                break;
            }
        }

        swap(nums[k], nums[l]);

        reverse(nums.begin()+k+1,nums.end());
    }
};