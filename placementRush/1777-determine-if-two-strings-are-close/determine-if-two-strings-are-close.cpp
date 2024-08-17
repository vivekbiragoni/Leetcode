class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int s1 = word1.size();
        int s2 = word2.size();
        if(s1!=s2) return false;
        unordered_map<char, int> freq1, freq2;
        unordered_set<char> set1, set2;

        
        for (char c : word1) {
            freq1[c]++;
            set1.insert(c);
        }

        for (char c : word2) {
            freq2[c]++;
            set2.insert(c);
        }

        if (set1 != set2) return false;

        vector<int> counts1, counts2;
        for (auto& [ch, freq] : freq1) {
            counts1.push_back(freq);
        }

        for (auto& [ch, freq] : freq2) {
            counts2.push_back(freq);
        }

        sort(counts1.begin(), counts1.end());
        sort(counts2.begin(), counts2.end());

        return counts1 == counts2;
    }
};