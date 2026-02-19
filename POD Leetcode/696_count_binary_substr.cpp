class Solution {
public:
    int countBinarySubstrings(string s) {
        int n = s.size();
        
        int ans = 0;
        int prev = 0;   // previous group size
        int curr = 1;   // current group size
        
        for(int i = 1; i < n; i++) {
            if(s[i] == s[i-1]) {
                curr++;
            } else {
                ans += min(prev, curr);
                prev = curr;
                curr = 1;
            }
        }
        
        // last group handle karna zaroori hai
        ans += min(prev, curr);
        
        return ans;
    }
};
