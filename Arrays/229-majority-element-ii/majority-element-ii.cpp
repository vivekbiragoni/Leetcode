class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> umap;
        vector<int> result;
        for(int num: nums){
            if(umap.find(num) != umap.end()){
                umap[num]++;
            }else{
                umap[num]=1;
            }
        }
        for(auto & pair : umap){
            if(pair.second > nums.size()/3){
                result.push_back(pair.first);
            }
        }
        return result;
    }
};