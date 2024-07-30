class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives = 0;
        int tens = 0;
        for (int i = 0; i < bills.size(); i++) {
            if (bills[i] == 5)
                fives++;
            else if (bills[i] == 10) {
                if (fives) {
                    fives--;
                    tens++;
                } else{
                    return false;
                }
            } else {
                if (fives && tens) {
                    fives--;
                    tens--;
                } else if (fives >= 3) {
                    fives -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};