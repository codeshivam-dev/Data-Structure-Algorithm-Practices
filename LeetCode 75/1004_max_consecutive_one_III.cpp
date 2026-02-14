class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0,j = 0;

        int mx = 0;

        while(j<n){
            if(nums[j] == 0) k--;
            
            while(i<=j && k < 0){
                if(nums[i] == 0) k++;
                i++;
            }
            mx = max(mx, j - i + 1);
            j++;
        }
        return mx;
    }
};