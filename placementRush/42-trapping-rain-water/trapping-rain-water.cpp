class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> prefix(n, -1);
        prefix[0]=height[0];
        for(int i = 1; i< n; i++){
            prefix[i]= max(prefix[i-1], height[i]);
        }
        vector<int> sufix(n,-1);
        sufix[n-1]=height[n-1];
        for(int i = n-2; i>=0; i--){
            sufix[i]=max(sufix[i+1], height[i]);
        }
        int tot = 0;
        for(int i = 0; i<n; i++){
            int leftmaxidx = prefix[i];
            int rightmaxidx = sufix[i];
            if(height[i]<leftmaxidx &&height[i]<rightmaxidx){
                tot += min(leftmaxidx, rightmaxidx)-height[i];
            }
        }
        return tot;
    }
};