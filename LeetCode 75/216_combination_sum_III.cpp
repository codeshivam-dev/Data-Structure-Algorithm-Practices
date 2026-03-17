class Solution {
public:
    vector<vector<int>> ans;

    void solve(int k, int n, vector<int>& curr, int num, int sum) {

        if (sum == n && curr.size() == k) {
            ans.push_back(curr);
            return;
        }

        if (num >= 9 || sum > n || curr.size() > k) return;

        int next = num + 1;

        // skip next number
        solve(k, n, curr, next, sum);

        // include next number
        curr.push_back(next);
        solve(k, n, curr, next, sum + next);
        curr.pop_back();
    }

    vector<vector<int>> combinationSum3(int k, int n) {

        ans.clear();
        vector<int> curr;

        solve(k, n, curr, 0, 0);

        return ans;
    }
};