class Solution {
public:
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto num : nums){
            mp[num]++;
        }
        vector<pair<int,int>> sorted(mp.begin(), mp.end());
        sort(sorted.begin(), sorted.end(), [](const pair<int, int>&a, const pair<int, int>&b){
            return a.second > b.second;
        });
        vector<int> answer;
        for(int i=0; i<k && i< sorted.size(); i++){
            answer.push_back(sorted[i].first);
        }
        return answer;
    }
};