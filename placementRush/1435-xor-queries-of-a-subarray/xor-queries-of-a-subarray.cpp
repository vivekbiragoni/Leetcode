class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        for(auto querie:queries){
            auto left = querie[0];
            auto right = querie[1];
            auto xorr = arr[left];
            for(int i = left+1; i<=right;i++){
                xorr^=arr[i];
            }
            ans.push_back(xorr);
        }
        return ans;
    }
};