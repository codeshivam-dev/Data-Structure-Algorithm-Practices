class Solution {
public:
    bool canEatAll(vector<int>& piles, int& h, int& k){
        long long time = 0;
        for(int& banana : piles){
            time += (banana + k - 1) / k;
        }

        return time <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = 1e9;
        int min_k = INT_MAX;
        while(left <= right){
            int k = (right - left) / 2 + left;

            if(canEatAll(piles, h, k)){
                right = k-1;
                min_k = k;
            }
            else left = k + 1;
        }

        return min_k;
    }
};