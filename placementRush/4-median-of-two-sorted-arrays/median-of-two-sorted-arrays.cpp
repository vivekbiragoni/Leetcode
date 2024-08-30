class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int totalSize = n1 + n2;
        int medianIndex = totalSize / 2;
        vector<int> merged;
        int i = 0, j = 0;
        while (i < n1 && j < n2 && merged.size() <= medianIndex) {
            if (nums1[i] < nums2[j]) {
                merged.push_back(nums1[i++]);
            } else {
                merged.push_back(nums2[j++]);
            }
        }

        while (i < n1 && merged.size() <= medianIndex) {
            merged.push_back(nums1[i++]);
        }

        while (j < n2 && merged.size() <= medianIndex) {
            merged.push_back(nums2[j++]);
        }

        if (totalSize % 2 == 0) {
            return (merged[medianIndex - 1] + merged[medianIndex]) / 2.0;
        } else {
            return merged[medianIndex];
        }
    }
};