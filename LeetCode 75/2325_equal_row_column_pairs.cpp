class Solution {
public:
    int equalPairs(vector<vector<int>>& arr) {
        int n = arr.size();
        int ans = 0;

        // map to store frequency of each row pattern
        map<vector<int>, int> mpp;

        // Step 1: Store all rows as vector pattern
        for(int i = 0; i < n; i++){
            vector<int> v;
            for(int j = 0; j < n; j++){
                v.push_back(arr[i][j]);   // build row i
            }
            mpp[v]++;   // increase frequency of this row pattern
        }
        
        // Step 2: Build each column and check if it matches any row
        for(int i = 0; i < n; i++){
            vector<int> v;
            for(int j = 0; j < n; j++){
                v.push_back(arr[j][i]);   // build column i (note index swap)
            }
            
            // if column pattern exists as row pattern
            if(mpp.find(v) != mpp.end()){
                ans += mpp[v];   // add its frequency
            }
        }

        return ans;
    }
};
