class Solution {
public:
    vector<int> findnse(vector<int>& heights){
        int n = heights.size();
        stack<int> st;
        vector<int> nse(n, n);

        for(int i = n-1; i>=0;i--){
            while(!st.empty()&& heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(!st.empty()){
                nse[i]=st.top();
            }
            st.push(i);
        }
        return nse;
    }
    vector<int> findpsee(vector<int>& heights){
        int n = heights.size();
        stack<int> st;
        vector<int> psse(n, -1);

        for(int i = 0; i<n;i++){
            while(!st.empty()&& heights[st.top()]>heights[i]){
                st.pop();
            }
            if(!st.empty()){
                psse[i]=st.top();
            }
            st.push(i);
        }
        return psse;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>nse =  findnse(heights);
        vector<int>pse =  findpsee(heights);
        int maxi = -1e9;
        for(int i = 0; i< n ; i++){
            maxi = max(maxi, heights[i]*(nse[i]-pse[i]-1));
        }
        return maxi;

    }
};