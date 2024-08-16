class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n = arrays.size();

        int minVal = arrays[0][0];
        int maxVal = arrays[0].back();
        
        int maxDistance = 0;
        
        // Iterate over the rest of the arrays
        for (int i = 1; i < n; ++i) {
            // Compute the distance by comparing the current array's min and max
            maxDistance = max(maxDistance, abs(arrays[i].back() - minVal));
            maxDistance = max(maxDistance, abs(maxVal - arrays[i][0]));
            
            // Update global min and max
            minVal = min(minVal, arrays[i][0]);
            maxVal = max(maxVal, arrays[i].back());
        }
        
        return maxDistance;
    }
};