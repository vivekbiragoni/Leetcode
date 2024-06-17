class Solution {
private:
    void backTrack(int k, int n, vector<int> &combination, vector<vector<int>> &result, int start){
        if(combination.size()==k && n == 0){
            result.push_back(combination);
            return;
        }

        if(combination.size()>k || n < 0) return;

        for(int i = start; i <= 9 ; ++i){
            combination.push_back(i);
            backTrack(k, n-i, combination, result, i+1);
            combination.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> combination;
        backTrack(k, n, combination, result, 1);
        return result;
    }
};