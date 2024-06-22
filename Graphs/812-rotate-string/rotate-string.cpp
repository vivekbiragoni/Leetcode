class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length()) return false;
        string concat = s + s;
        return concat.find(goal) != string::npos;
    }
};