class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;

        int mx = 0, cnt = 0;

        while(j < n){
            if(nums[j] == 0) cnt++;

            while(i <= j && cnt > 1){
                if(nums[i] == 0) cnt--;
                i++;
            }
            mx = max(mx, j - i);
            j++;
        }
        return mx;
        
    }
};