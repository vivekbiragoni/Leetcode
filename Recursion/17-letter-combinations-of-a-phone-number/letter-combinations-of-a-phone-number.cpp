class Solution {
private:
    void backTrack(vector<string> & result, string& combination, const vector<string>&digitToLetters, const string &digits, int index){
        if(index == digits.size()){
            result.push_back(combination);
            return;
        }
        string letters = digitToLetters[digits[index]-'0'];

        for(char letter: letters){
            combination.push_back(letter);
            backTrack(result, combination, digitToLetters, digits, index+1);
            combination.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> digitToLetters = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        vector<string> result;
        string combination;
        backTrack(result, combination, digitToLetters, digits, 0);
        return result;
    }
};