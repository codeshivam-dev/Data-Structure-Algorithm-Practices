class Solution {
    public int dominantIndices(int[] nums) {
        int n = nums.length;
        int total_sum = 0;

        for(int i =0; i<n; i++) total_sum += nums[i];

        int cnt = 0, prefix_sum = 0;
        for(int i =0; i<n-1; i++) {
            prefix_sum += nums[i];
            int r = n - i - 1;

            int avg = (total_sum - prefix_sum) / r;
            if(nums[i] > avg) cnt++;
        }

        return cnt;
    }
}