class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xorr = start^goal;
        int cont = 0;
        while(xorr){
            cont += xorr &1;
            xorr>>=1;
        }
        return cont;
    }
};