class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxi = 0;
        int n = gain.size();
        int cumsum = 0;
        for(int i = 0; i< n; i++){
            cumsum += gain[i];
            maxi = max(maxi, cumsum);
        }
        return maxi;
    }
};