class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> mt(m, vector<int>(n));
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(j == 0) mt[i][j] = grid[i][j];
                else mt[i][j] = mt[i][j-1] + grid[i][j];
            }
        }

        int cnt = 0; 
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                
                if(i != 0) {
                    mt[i][j] += mt[i-1][j];
                    if(mt[i][j] <= k) cnt++;
                }
                else if(mt[i][j] <= k) cnt++;
            }
        }
        return cnt;
    }
};