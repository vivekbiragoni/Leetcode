class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int sz = nums.size();
        int low = 1;
        int high = sz-2;
        if(sz==1) return nums[0];
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[sz-1] != nums[sz-2]) return nums[sz-1];

        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid]!=nums[mid+1] && nums[mid] != nums[mid-1])
                return nums[mid];
            if((mid%2==0 && nums[mid]==nums[mid+1]) || (mid%2==1 && nums[mid]==nums[mid-1])){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return -1;
    }
};

// each element is in pairs, that is 
// on the left side of the single element, pairs are in the even and odd sequence of index.
// on the right side of the single element, pairs are in the odd and even sequence of index.
// eliminator if condition looks for the same, and if a part on the array follows the if condtion
// then that part woould never contain the single element and also there are two conditions 
// for this if block, i.e, when mid is on the even or the odd index. 

