class Solution {
public:

    long long findHour(int k, const vector<int>& piles) {
        long long hour = 0;
        for (int num : piles) {
            hour += (num + (long long)k - 1) / k;  // ceil(num / k)
        }
        return hour;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long requiredHour = findHour(mid, piles);

            if (requiredHour <= h) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
