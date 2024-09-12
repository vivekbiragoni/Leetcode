class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int asize = allowed.size();
        int wsize = words.size();
        unordered_set<char> st(allowed.begin(), allowed.end());
        
        int ncont = 0;
        for (auto word : words) {
            for (char c : word) {
                if (st.find(c) == st.end()) {
                    ncont++;
                    break;
                } else {
                    continue;
                }
            }
        }

        return wsize - ncont;
    }
};