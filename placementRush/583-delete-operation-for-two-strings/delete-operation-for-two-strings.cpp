class Solution {
public:
    int lcs(string& text1, string& text2) {
        int l1 = text1.size();
        int l2 = text2.size();
        vector<int> prev(l2 + 1, 0), cur(l2 + 1, 0);
        for (int ind1 = 1; ind1 <= l1; ind1++) {
            for (int ind2 = 1; ind2 <= l2; ind2++) {
                if (text1[ind1 - 1] == text2[ind2 - 1]) {
                    cur[ind2] = 1 + prev[ind2 - 1];
                } else {
                    cur[ind2] = max(prev[ind2], cur[ind2 - 1]);
                }
            }
            prev = cur;
        }
        return cur[l2];
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        return n + m - 2 * lcs(word1, word2);
    }
};