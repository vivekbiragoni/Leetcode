class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        cout<<m<<endl;
        int summ = 0;
        for(auto num : rolls){
            summ += num;
        }
        cout<<summ<<endl;
        int rem = (mean*(m+n))- summ;
        cout<<rem<<endl;
        if(rem/n>6||rem/n<=0){
            return {};
        }

        vector<int> ans(n, rem/n);
        int k=rem%n;
        cout<<rem/n;
        // if(rem%n!=0){
        //      ans[n-1] = rem-((rem/n)*(n-1));
        //     //  if(ans[n-1]>6){
        //     //     return {};
        //     //  }
        // }
        for(int i=0;i<k;i++){
            ans[n-i-1]++;
            if(ans[n-i-1]>6){
                return {};
             }
        }

        return ans;
       
    }
};