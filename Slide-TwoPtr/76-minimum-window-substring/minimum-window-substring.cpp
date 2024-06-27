class Solution {
public:
    string minWindow(string s, string t) {
        int left = 0;
        int right = 0;
        int count = t.length();
        int sIndex = 0;
        int minLen = INT_MAX;

        if(s.empty()||t.empty() || s.length()< t.length()){
            return "";
        }

        vector<int> map(128,0);
        for(char c: t){
            map[c]++;
        }

        while(right < s.length()){
            if(map[s[right++]]-- > 0){
                count--;
            }
            while(count == 0){
                if(right - left < minLen){
                    sIndex = left;
                    minLen = right - left;
                }
                if(map[s[left++]]++ == 0){
                    count++;
                }
            }
        }
        return minLen == INT_MAX ? "" : s.substr(sIndex, minLen);
    }
};