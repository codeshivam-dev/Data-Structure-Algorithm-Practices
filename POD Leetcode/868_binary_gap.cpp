class Solution {
public:
    int binaryGap(int n) {
        int last = -1;
        int pos = 0;
        int mx = 0;

        while (n) {
            if (n & 1) {
                if (last != -1)
                    mx = max(mx, pos - last);
                last = pos;
            }
            pos++;
            n >>= 1;
        }
        return mx;
    }
};