class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives = 0;
        int tens = 0;
        int n = bills.size();
        for (int i = 0; i < n; i++) {
            if (bills[i] == 5) {
                fives++;
            } else if (bills[i] == 10) {
                if (fives) {
                    tens++;
                    fives--;
                }else{
                    return false;
                }
            } else if (bills[i] == 20) {
                if(fives && tens){
                    fives--;
                    tens--;
                }else if(fives>=3){
                    fives-=3;
                }else {
                    return false;
                }
            }
        }
        return true;
    }
};