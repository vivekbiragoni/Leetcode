class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n,-1);
        int cumsum = 0;
        for(int i = 0; i< n; i++){
            cumsum=nums[i]+cumsum;
            prefix[i] = cumsum;
        }
        vector<int>suffix(n, -1);
        int cumsum2 = 0;
        for(int i = n-1; i>=0; i-- ){
            cumsum2=nums[i]+cumsum2;
            suffix[i]=cumsum2;
        }
        for(int i= 0; i< n; i++){
            if(prefix[i]==suffix[i]){
                return i;
            }
        }
        return -1;
    }
};