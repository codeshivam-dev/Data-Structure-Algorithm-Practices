class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int right[n];
        right[n-1] = nums[n-1];
        for(int i = n-2; i>=0; i--){
            right[i] = right[i+1] + nums[i];
        }

        int sum = 0;
        for(int i = 0; i<n; i++){
            sum += nums[i];
            if(sum == right[i]){
                return i;
            }
        }
        return -1;
    }
};