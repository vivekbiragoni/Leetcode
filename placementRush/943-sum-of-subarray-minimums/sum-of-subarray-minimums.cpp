class Solution {
public:
    const int MOD = (int)(1e9 + 7);

    vector<int> findnse(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n, n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (st.empty()) {
                nse[i] = n;
            } else {
                nse[i] = st.top();
            }
            st.push(i);
        }
        return nse;
    }

    vector<int> findpsee(vector<int>& arr) {
        int n = arr.size();
        vector<int> psee(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            psee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return psee;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long tot = 0;
        vector<int> nse = findnse(arr);
        vector<int> psee = findpsee(arr);
        for (int i = 0; i < n; i++) {
            int left = i - psee[i];
            int right = nse[i] - i;
            tot = (tot + (long long)right * left * arr[i]) % MOD;
        }
        return (int)tot;
    }
};