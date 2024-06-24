class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int left = k-1;
        int lsum = 0;
        int rsum = 0;
        int n = cardPoints.size();
        for(int i = 0; i < k ; i++){
            lsum += cardPoints[i];
        }
        int tSum = lsum;
        int maxSum = lsum;
        int right = n-1;
        while(right >= n-k){
            rsum += cardPoints[right];
            right--;
            lsum = lsum - cardPoints[left];
            left--;
            tSum = lsum + rsum;
            maxSum = max(maxSum, tSum);
        }
        return maxSum;
    }
};