class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for(auto x : s){
            if(x=='(' || x == '{' || x == '['){
                st.push(x);
            }
            else if(x ==')' || x =='}' || x == ']'){
                if(st.empty()){
                    return false;
                }
                char y = st.top();
                st.pop();
                if ((x == ')' && y != '(' ) || (x=='}' && y != '{') || (x==']' && y!= '[')){
                    return false;
                }

            }
        }
        return st.empty();

    }
};