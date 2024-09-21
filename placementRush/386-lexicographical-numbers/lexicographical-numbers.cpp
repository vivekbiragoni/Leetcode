class Solution {
public:
    void generateLexical(int i, int n, vector<int> & ans){
        if(i>n) return;
        ans.push_back(i);
        for(int nxtdig= 0; nxtdig<=9; nxtdig++){
            int nxtnum = i * 10 + nxtdig;
            if(nxtnum<=n){
                generateLexical(nxtnum, n, ans);
            }else{
                break;
            }
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int i = 1; i<=9; i++){
            generateLexical(i,n,ans);
        }
    return ans;
    }
};