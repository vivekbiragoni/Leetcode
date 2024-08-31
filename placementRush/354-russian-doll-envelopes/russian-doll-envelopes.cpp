class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b){
        if(a[0]==b[0]) return a[1]>b[1];
        return a[0]<b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), comp);
        vector<int> hts;
        for(auto env: envelopes){
            hts.push_back(env[1]);
        }


        vector<int> dp;
        for(auto ht: hts){
            auto it = lower_bound(dp.begin(), dp.end(), ht);
            if(it==dp.end()){
                dp.push_back(ht);
            }else{
                *it = ht;       
            }
        }
        return dp.size();
    }
};