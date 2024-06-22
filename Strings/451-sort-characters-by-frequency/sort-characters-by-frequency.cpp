class Solution {
public:
    static bool sortByFrequency(const pair<char,int> &a, const pair<char, int>&b){
        if(a.second!=b.second){
            return a.second>b.second;
        }
        return a.first<b.first;
    }
    string frequencySort(string s) {
        unordered_map<char, int> umap;
        for(char ch : s){
            umap[ch]++;
        }
        vector<pair<char,int>> freqVec(umap.begin(), umap.end());

        sort(freqVec.begin(),freqVec.end(),sortByFrequency);

        string result;
        for(auto & entry : freqVec){
            result += string(entry.second, entry.first);
        }

        return result;

    }
};