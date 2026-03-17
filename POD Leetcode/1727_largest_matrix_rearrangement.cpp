class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int maxArea = 0;

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(matrix[i][j] == 1 && i > 0){
                    matrix[i][j] += matrix[i-1][j];
                }
            }

            vector<int>height = matrix[i];
            sort(height.begin(), height.end(), greater<int>());

            for(int k = 0; k<n; k++){
                int base = k+1;
                maxArea = max(maxArea, height[k] * base);
            }
        }

        return maxArea;
    }
};