class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int m = g.size();
        int n = s.size();
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int n_child = 0;
        int n_cookie = 0;
        while(n_child < m && n_cookie < n){
            if(g[n_child]<=s[n_cookie]){
                n_child++;
            }
            n_cookie++;
        }
        return n_child;
    }
};