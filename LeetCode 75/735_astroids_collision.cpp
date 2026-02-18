class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        int n = arr.size();
        vector<int>ans;

        for(int num : arr){
            if(ans.empty() || num > 0) ans.push_back(num);
            else{
                while(!ans.empty() && ans.back() > 0 && ans.back() < abs(num)) ans.pop_back();
                if(!ans.empty() && ans.back() == abs(num)) ans.pop_back();
                else if(ans.empty() || ans.back() < 0) ans.push_back(num);
            }
        }
        return ans;
    }
};