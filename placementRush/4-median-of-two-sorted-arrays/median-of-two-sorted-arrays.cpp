class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int totalSize = n1 + n2;
        int medianIndex = totalSize / 2;
        vector<int> merged;
        int i = 0, j = 0, count = 0;
        int prev = 0, current = 0;
        
        while (count <= medianIndex) {
            prev = current;
            if (i == n1) {
                current = nums2[j];
                j++;
            } else if (j == n2) {
                current = nums1[i];
                i++;
            } else if (nums1[i] < nums2[j]) {
                current = nums1[i];
                i++;
            } else {
                current = nums2[j];
                j++;
            }
            count++;
        }
        
        if (totalSize % 2 == 0) {
            return (prev + current) / 2.0;
        } else {
            return current;
        }
    }
};