class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()) return 0;
        int n = height.size();
        int left = 0, right = n-1;
        int left_max = 0, right_max = 0;
        int tot = 0;


        while(left<=right){
            if(height[left]<=height[right]){
                if(height[left]>=left_max){
                    left_max = height[left];
                }else{
                    tot += left_max - height[left];
                }
                left++;
            }else{
                if(height[right]>=right_max){
                    right_max = height[right];
                }else{
                    tot+= right_max - height[right];
                }
                right--;
            }
        }
        return tot;
    }
};