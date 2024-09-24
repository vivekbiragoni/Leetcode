class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int gs) {
        int n = hand.size();
        if(n%gs!=0 || n< gs) return false;

        map<int,int> freq;
        for(auto h: hand){
            freq[h]++;
        }
        while(!freq.empty()){
            int curcard = freq.begin()->first;
            for(int i = 0; i<gs; i++){
                if(freq[curcard+i]==0) return false;
                freq[curcard+i]--;
                if(freq[curcard+i]<1) freq.erase(curcard+i);
            }
        }
        return true;
    }
};