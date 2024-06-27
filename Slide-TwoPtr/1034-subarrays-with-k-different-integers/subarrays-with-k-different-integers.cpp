class Solution {
public:
    int subarraysWithKDistinctHelper(vector<int>& nums, int k) {
        int left = 0;
        int cont = 0;
        int right = 0;
        unordered_map<int,int> umap;
        while(right < nums.size()){
            umap[nums[right]]++;

            while(umap.size()>k){
                umap[nums[left]]--;
                if(umap[nums[left]]==0){
                    umap.erase(nums[left]);
                }
                left++;
            }
            cont = cont + (right - left +1);
            right++;
        }
        return cont;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarraysWithKDistinctHelper(nums, k) - subarraysWithKDistinctHelper(nums, k-1);
    }
};