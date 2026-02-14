class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        
        int z = -1;   // pointer to first zero
        int nz = 0;   // pointer to scan for non-zero elements

        // Step 1: Find the first zero in the array
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0){
                z = i;
                nz = i;
                break; 
            }
        }

        // Step 2: Move non-zero elements to the position of zero
        while(nz < n){
            
            // If current element is non-zero and we have a zero position
            if(z != -1 && nums[nz] != 0){
                swap(nums[nz], nums[z]);  // bring non-zero forward
            }

            // Move zero pointer forward to next zero position
            while(z != -1 && z < nz && nums[z] != 0){
                z++;
            }

            nz++;  // continue scanning
        }
    }
};
