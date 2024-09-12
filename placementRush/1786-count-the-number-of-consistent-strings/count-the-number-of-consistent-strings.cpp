class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int asize = allowed.size();
        int wsize = words.size();

        unordered_map<char, bool> mp;
        for(char c: allowed){
            if(mp.find(c)==mp.end()){
                mp[c]=true;
            }else continue;
        }
        int ncont = 0;
        for(auto word: words){
            for(char c: word){
                if(mp.find(c)==mp.end()){
                    ncont++;
                    break;
                }else if(mp[c]==true){
                    continue;
                }
            }
        }

        return wsize - ncont;
    }
};