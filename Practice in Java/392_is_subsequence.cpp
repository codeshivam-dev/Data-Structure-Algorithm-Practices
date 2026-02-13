class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size();
        if(n==0) return true;
        if(t.size()==0) return false;
        
        int i = 0;
        for(char ch: t){
            if(ch == s[i]) i++;
            if(i == n) return true;
        }

        return false;
    }
};