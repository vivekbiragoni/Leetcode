class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if (k >= n) return "0";
        stack<char> st;
        // int n = num.size();
        for(int i = 0; i< n; i++){
            while(!st.empty()&& k>0 && st.top()-'0' > num[i]-'0'){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k>0&&!st.empty()){
            st.pop();
            k--;
        }
        if(st.empty()) return "0";
        string res; 
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        
        // Remove leading zeros
        int start = 0;
        while (start < res.size() && res[start] == '0') {
            start++;
        }

        // Return "0" if the string is empty or only contained zeros
        res = res.substr(start);
        return res.empty() ? "0" : res;
    }
};