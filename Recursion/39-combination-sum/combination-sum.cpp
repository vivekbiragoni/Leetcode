class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> combination;
        backTrack(candidates, target, combination, result, 0);
        return result;
    }
private:
    void backTrack(vector<int> &candidates, int target,vector<int> &combination, vector<vector<int>> &result, int start){
        if(target == 0){
            result.push_back(combination);
            return;
        }
        if(target < 0)
            return ;

        for(int i = start; i < candidates.size(); ++i){
            combination.push_back(candidates[i]);
            backTrack(candidates, target - candidates[i], combination, result, i);
            combination.pop_back();
        }
    }
};