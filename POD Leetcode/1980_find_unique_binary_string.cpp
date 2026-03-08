class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();

        string ans = nums[0];
        for(int i = 0; i<n; i++){
            ans[i] = (ans[i] == '0') ? '1':'0';
            bool exist = false;
            for(int j = 0; j<n; j++){
                if(ans == nums[j]) {
                    exist = true;
                    break;
                }
            }

            if(exist == false) return ans;
        }

        return "";
    }
};