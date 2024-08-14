class Solution {
public:
    int hist(vector<int>&nums){
        int n = nums.size();
        stack<int> st;
        int maxarea = 0;
        for(int i = 0; i<n; i++){
            while(!st.empty()&&nums[st.top()]>nums[i]){
                int nse = i;
                int ele = st.top();
                st.pop();
                int pse = st.empty()?-1:st.top();
                maxarea = max(maxarea, (nse-pse-1)*nums[ele]);
            }
            st.push(i);
        }
        while(!st.empty()){
            int nse = n; 
            int ele = st.top();
            st.pop();
            int pse = st.empty()?-1:st.top();
            maxarea = max(maxarea, (nse-pse-1)*nums[ele]);
        }
        return maxarea;
        
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        int maxarea = 0;
        vector<int> psum(m, 0); 

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                
                psum[j] = (matrix[i][j] == '1') ? psum[j] + 1 : 0;
            }
            
            maxarea = max(maxarea, hist(psum));
        }
        return maxarea;
    }
};