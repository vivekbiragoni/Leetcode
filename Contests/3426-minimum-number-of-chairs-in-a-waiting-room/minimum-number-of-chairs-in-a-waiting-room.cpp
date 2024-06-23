class Solution {
public:
    int minimumChairs(string s) {
        int currentppl = 0;
        int maxppl = 0;
        for(char c : s){
            if(c=='E'){
                currentppl++;
                if(currentppl>maxppl){
                    maxppl = currentppl;
                }
            }else if (c=='L'){
                currentppl--;
            }
        }
        return maxppl;
    }
};