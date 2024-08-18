class Solution {
public:
    int nthUglyNumber(int n) {
        vector<long long> ans;
        // ans[0]=1;
        priority_queue<long long, vector<long long>, greater<long long>> minheap;
        unordered_set<long long> st;

        minheap.push(1);
        minheap.push(2);
        minheap.push(3);
        minheap.push(5);

        st.insert(1);
        st.insert(2);
        st.insert(3);
        st.insert(5);

        while(ans.size()<n){
            long long ele = minheap.top();
            minheap.pop();
            ans.push_back(ele);
            long long nums[]= {ele*2, ele*3, ele*5};
            for(long long num: nums){
                if(st.find(num)==st.end()){
                    st.insert(num);
                    minheap.push(num);
                }
            }
            
        }
        return int(ans[n-1]);
    }
};