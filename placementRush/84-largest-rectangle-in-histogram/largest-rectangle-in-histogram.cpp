class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxarea = -1e9;

        for(int i = 0; i< n; i++){
            while(!st.empty()&&heights[st.top()]>heights[i]){
                int element = st.top();
                st.pop();
                int nse = i;
                int pse = st.empty()?-1:st.top();
                maxarea = max(heights[element]*(nse-pse-1), maxarea);
            }
            st.push(i);
        }
        while(!st.empty()){
            int nse = n;
            int element = st.top();
            st.pop();
            int pse = st.empty()?-1:st.top();
            maxarea = max(maxarea, (nse-pse-1)*heights[element]);
        }
        return maxarea;
    }
};