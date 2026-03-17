class Solution {
public:
    vector<string> mpp = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;

    void solve(string digits, int idx, string s){
        if(idx == digits.size()){
            ans.push_back(s);
            return;
        }

        string curr = mpp[digits[idx] - '0']; // string crossponding to digits

        for(int i = 0; i < curr.size(); i++){
            s.push_back(curr[i]);
            solve(digits, idx+1, s);
            s.pop_back();
        }

        return;
    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};

        ans.clear();
        solve(digits, 0, "");
        return ans;
    }
};