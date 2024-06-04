class Solution {
private:
    string trim(const string& str){
        size_t start = 0 ;
        size_t end = str.size()-1;

        while(start<=end && str[start]==' '){
            start++;
        }
        while(end>=start && str[end]== ' '){
            end--;
        }
        return str.substr(start, end-start+1);
    }
    
public:
    string reverseWords(string str) {
        string trimmed = trim(str);

        vector<string> words;

        stringstream ss(trimmed);

        string word;
        while(ss>>word){
            words.push_back(word);
        }
        reverse(words.begin(), words.end());

        
        stringstream reversed_ss;
        for (size_t i = 0; i < words.size(); ++i) {
            reversed_ss << words[i];
            if (i < words.size() - 1) {
                reversed_ss << ' '; 
            }
        }

        return reversed_ss.str();
        
    }
};