
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>, greater<int>> pq;
        for (int i = 0; i < nums.size(); i++) {
            if (pq.size() < k) {
                pq.push(nums[i]);
            } else {
                int ele = pq.top();
                if(ele<nums[i]){
                    pq.pop();
                    pq.push(nums[i]);
                }
                
            }
        }
        return pq.top();
    }
};