class Solution {
public:
    int guessNumber(int n) {
        int i = 1;
        while(i <= n) {
            int mid = (n - i)/2 + i;

            int possible = guess(mid);
            if(possible == 0) return mid;
            else if(possible == -1) n = mid - 1;
            else i = mid + 1;
        }
        return 0;
    }
};