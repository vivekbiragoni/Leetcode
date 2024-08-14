class Solution {
public:
    int countpairswithmaxdist(vector<int>&nums, int mid){
        int count = 0;
        int n = nums.size();
        int left = 0;
        for(int r =1; r<n; r++){
            while(nums[r]-nums[left]>mid){
                left++;
            }
            count += r - left;
        }
        return count;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int low = 0;
        int high = nums[n-1]-nums[0];

        while(low<high){
            int mid = (low+high)/2;
            int cont = countpairswithmaxdist(nums, mid);
            if(cont<k){
                low = mid+1;
            }else{
                high = mid;
            }
        }
        return low;
    }
};