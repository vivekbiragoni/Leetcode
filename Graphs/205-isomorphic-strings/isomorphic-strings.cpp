class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length()) return false;

        unordered_map<char, char> mapST;
        unordered_map<char, char> mapTS;

        for(int i = 0; i < s.length(); i++){
            char charS = s[i];
            char charT = t[i];

            if(mapST.find(charS)!=mapST.end()){
                if(mapST[charS]!=charT) return false;
            }else{
                mapST[charS] = charT;
            }

            if(mapTS.find(charT)!=mapTS.end()){
                if(mapTS[charT]!=charS) return false;
            }else{
                mapTS[charT] = charS;
            }
        }
        return true;
    }
};