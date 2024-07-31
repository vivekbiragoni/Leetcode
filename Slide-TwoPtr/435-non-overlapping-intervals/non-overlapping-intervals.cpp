bool comp(const vector<int>&a, const vector<int>&b){
    return a[1]<b[1];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
       
        int n = intervals.size();
        if(n==0) return 0;

        sort(intervals.begin(), intervals.end(), comp);

        int freetime  = intervals[0][1];
        int cont = 1;
        for(int i = 1; i < n; i++){
            if(intervals[i][0]>=freetime){
                cont++;
                freetime = intervals[i][1];
            }
        }
        return n - cont;
    }
};