class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if (n == 0) return 0; 
        if(n == 1) return 1;
        unordered_map<char, int> charIndexMap;
        int left = 0;
        int maxLength = 0;

        for(int right = 0; right < n; right++){
            if(charIndexMap.find(s[right])!=charIndexMap.end() && charIndexMap[s[right]]>=left){
                left = charIndexMap[s[right]] + 1;
            }
            charIndexMap[s[right]] = right ;
            maxLength = max(maxLength, right - left +1 );
        }
        return maxLength;
    }
};