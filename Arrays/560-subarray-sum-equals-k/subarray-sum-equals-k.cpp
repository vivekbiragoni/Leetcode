class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> cumSumMap;
        cumSumMap[0] = 1;
        int cumSum = 0;
        int count = 0;

        for(int num: nums){
            cumSum += num;

            if(cumSumMap.find(cumSum-k)!=cumSumMap.end()){
                count += cumSumMap[cumSum-k];
            }

            cumSumMap[cumSum]++;

        }

        return count;
    }
};