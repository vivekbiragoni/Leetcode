class Solution {
private:
    long helper(string s, int i,int n, int sign, long result){
        if(i >= n || s[i]<'0'||s[i]>'9') return sign*result;

        int digit = s[i]-'0';
        if(sign==1 && result>(INT_MAX-digit)/10) return INT_MAX;
        if(sign==-1 && -result<(INT_MIN+digit)/10) return INT_MIN;

        result = result * 10 + digit;
        return  helper(s, i+1, n, sign,  result);
    }
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0, sign = 1;
        while (i < n && s[i] == ' ')
            i++;

        if (s[i] == '-') {
            sign = -1;
            i++;
        } else if (s[i] == '+') {
            sign = 1;
            i++;
        }

        return helper(s, i,n, sign, 0);
    }
};