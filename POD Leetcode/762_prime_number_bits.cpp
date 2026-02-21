class Solution {
public:
    int prime[11] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    bool isPrime( int bit){
        for(int i = 0; i<11; i++) {
            if(prime[i] == bit) return true;
        }
        return false;
    }
    int countPrimeSetBits(int left, int right) {
        int  cnt = 0;

        while(left<=right){
            int s_bit = __builtin_popcount(left);
            if(isPrime(s_bit)) cnt++;
            left++;
        }
        return cnt;
    }
};