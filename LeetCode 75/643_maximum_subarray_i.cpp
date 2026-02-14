class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0; 
        int sum = 0;
        double maxi = -1e18;

        while(j < n){
            sum += nums[j];

            if(j - i + 1 == k){
                maxi = max(maxi, sum * 1.0 / k);
                sum -= nums[i];
                i++;
            }
            j++;
        }
        return maxi;
    }
};
