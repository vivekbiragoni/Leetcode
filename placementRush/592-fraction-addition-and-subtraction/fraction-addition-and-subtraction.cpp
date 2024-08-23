class Solution {
public:
    string fractionAddition(string expression) {
        int num = 0;
        int denom = 1;

        int i = 0;
        while(i<expression.size()){
            int currNum = 0;
            int currDenom = 0;
            bool isNegative = false;
            // look for sign
            if(expression[i]=='-'||expression[i]=='+'){
                if(expression[i]=='-'){
                    isNegative = true;
                }
                i++;
            }
            // numerator
            while(isdigit(expression[i])){
                int val = expression[i]-'0';
                currNum = currNum*10 +val;
                i++;
            }
            // turns the numerator neg. if it was neg
            if(isNegative) currNum *= -1;
            // skips the divisor char
            i++;
            // denom
            while(i<expression.size()&& isdigit(expression[i])){
                int val = expression[i]-'0';
                currDenom = currDenom * 10 +val;
                i++;
            }

            num = num*currDenom + currNum * denom;
            denom = denom * currDenom;
        }
        int gcd = abs(Findgcd(num, denom));

        num /= gcd;
        denom /= gcd;

        return to_string(num)+"/"+to_string(denom);
    }
    private:
    int Findgcd(int a, int b){
        if(a==0) return b;
        return Findgcd(b%a, a);
    }
};