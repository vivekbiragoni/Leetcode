#include <regex>
class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        
        // Remove non-alphanumeric characters
        s.erase(remove_if(s.begin(), s.end(), [](unsigned char x){ return!isalnum(x); }), s.end());
        
        int i = 0;
        int j = s.size()-1;
        // for (auto& x : s) { 
        // x = tolower(x); 
        // } 
        // regex pattern("\\W+");
        // regex_replace(s, pattern, "");
        while(i<=j){
            if (s[i]!=s[j])
                return false;
            else{
                i++;
                j--;
            }
            
        }
        return true;
    }
};