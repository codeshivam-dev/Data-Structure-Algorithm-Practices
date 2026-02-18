class Solution {
public:
    bool hasAlternatingBits(int n) {
        int f = -1;
        while(n){
            int c = n & 1;
            if(f == c) return false;
            f = c;
            n = n>>1;
        }
        return true;
    }
};