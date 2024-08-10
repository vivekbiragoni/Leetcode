class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);  //remove from set if pushed to queue.. no repetetions

        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(word==endWord) return steps;
            for(int i = 0; i < word.size(); i++){
                string original = word;
                for (char ch = 'a'; ch<='z'; ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        st.erase(word);
                        q.push({word, steps+1});
                    }
                }
                word=original;
            }
        }
        return 0;
    }
};