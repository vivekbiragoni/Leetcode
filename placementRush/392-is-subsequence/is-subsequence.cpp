class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size()>t.size()) return false;
        int i = 0, j = 0;
        for(; i<s.size(), j<t.size(); j++){
            if(s[i]==t[j]){
                i++;
            }
        }
        if(i==s.size()) return true;
        return false;
    }
};