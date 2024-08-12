class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int n = nums2.size();
        stack<pair<int, int>> st;
        unordered_map<int, int> ngeMap;  // To store the next greater element for each element in nums2
        
        // Start from the end of nums2 and find the next greater element for each
        for (int i = n - 1; i >= 0; i--) {
            int current = nums2[i];
            
            // Pop elements from the stack that are less than or equal to the current element
            while (!st.empty() && st.top().first <= current) {
                st.pop();
            }
            
            // If the stack is empty, no greater element exists for current
            if (st.empty()) {
                ngeMap[current] = -1;
            } else {
                // The top element on the stack is the next greater element
                ngeMap[current] = st.top().first;
            }
            
            // Push the current element onto the stack
            st.push({current, i});
        }
        // For each element in nums1, find its next greater element using the map
        for (int i = 0; i < nums1.size(); i++) {
            ans.push_back(ngeMap[nums1[i]]);
        }
        
        return ans;
    }
};