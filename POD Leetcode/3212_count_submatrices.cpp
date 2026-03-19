class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<pair<int,int>>> prefix(m, vector<pair<int,int>>(n, {0,0}));

        int cnt = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){

                int currX = (grid[i][j] == 'X') ? 1 : 0;
                int currY = (grid[i][j] == 'Y') ? 1 : 0;

                int topX = (i > 0) ? prefix[i-1][j].first : 0;
                int leftX = (j > 0) ? prefix[i][j-1].first : 0;
                int diagX = (i > 0 && j > 0) ? prefix[i-1][j-1].first : 0;

                int topY = (i > 0) ? prefix[i-1][j].second : 0;
                int leftY = (j > 0) ? prefix[i][j-1].second : 0;
                int diagY = (i > 0 && j > 0) ? prefix[i-1][j-1].second : 0;

                int totalX = currX + topX + leftX - diagX;
                int totalY = currY + topY + leftY - diagY;

                prefix[i][j] = {totalX, totalY};

                // condition check
                if(totalX > 0 && totalX == totalY){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};