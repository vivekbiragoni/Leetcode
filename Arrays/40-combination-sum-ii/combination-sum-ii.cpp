class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> combination;
        sort(candidates.begin(), candidates.end());
        backTrack(result, combination, candidates, target, 0);
        return result;
    }
    void backTrack(vector<vector<int>> &result, vector<int>&combination, vector<int> &candidates,int target,  int start){
        if(target == 0){
            result.push_back(combination);
            return;
        }
        if(target < 0) return;

        for(int i = start; i < candidates.size(); ++i){
            if(i > start && candidates[i]== candidates[i-1]) continue;
            combination.push_back(candidates[i]);
            backTrack(result, combination, candidates, target-candidates[i], i+1);
            combination.pop_back();
        }
    }
};