class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n  = nums.size();
        sort(nums.begin(), nums.end());

        int l = 0, r = n - 1, cnt = 0;
        while(l < r){
            if(nums[l] + nums[r] == k) {
                cnt++;
                l++;
                r--;
            }
            else if(nums[l] + nums[r] < k) l++;
            else r--;
        }
        return cnt;
    }
};