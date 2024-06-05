class Solution {

public:
    int mod = 1e9 + 7;
    long long power(long long x, long long y){
        long long res = 1;

        x = x % mod;
        if(x==0) return 0;

        while(y>0){
            if( y & 1) res = (res * x ) % mod;

            y = y >> 1;
            x = (x * x) % mod; 
        }
        return res;

    }
    
    int countGoodNumbers(long long n) {
        long long count_of_4s = n/2;
        long long count_of_5s = (n-n/2);
        long long ans = ((power(4LL, count_of_4s))%mod * (power(5LL, count_of_5s)%mod)%mod);
        return (int)ans;
    }
};