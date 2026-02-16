class Solution {
public:
    int reverseBits(int n) {
        if(n <= 1) return n;

        int ans = 0;
        for(int i = 0; i <= 31; i++){
            if((n>>i) & 1) {
                ans+= pow(2, 31-i);
            }
        }
        return ans;
    }
};