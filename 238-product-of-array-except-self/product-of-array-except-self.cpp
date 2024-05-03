class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // first thought: use two pointers, i at present index, and j to travese through 
        // array and skip the element if i==j
        // didnt work

        // based on the hint, use prefix product and suffix product
        vector<int> answer(nums.size(), 1);
        int prefix = 1;
        for(int i =0; i < nums.size(); i++){
            answer[i] = prefix;
            prefix *= nums[i];
        }
        int postfix = 1;
        for(int i = nums.size()-1; i>=0;i--){
            answer[i] *= postfix;
            postfix *= nums[i]; 
        }
        return answer;

    }
};