class Solution {
public:
    bool isAnagram(string s, string t) {
        // Planning to use unordered_map, to go through the string s and store its frequency, and check if the 
        // t's elements also have the same frequency or not
        unordered_map<char, int> mp;

        for(char x:s){
                mp[x]++;
        }

        for(char y:t){
            if(mp.find(y)==mp.end()||mp[y]==0){
                return false;
            }
            mp[y]--;
            }
        for(auto pair: mp){
            if(pair.second!=0){
                return false;
            }
                
        }
        return true;    
        }
};