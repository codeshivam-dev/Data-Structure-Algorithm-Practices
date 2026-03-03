class Solution {
public:
    char findKthBit(int n, int k) {
        if(n == 1) return '0';

        int len = (1 << n) - 1; // finding lenght 

        if(k < ceil(len/2.0)){
            return findKthBit(n-1, k);
        }
        else if(k == ceil(len/2.0)) return '1'; // middle case
        else {
            char ch = findKthBit(n-1, len - (k - 1)); // reverse string logic by position
            return (ch == '0') ? '1': '0'; // flip bits logic
        }
    }
};