class Solution {
public:
    string removeStars(string s) {
        int n = s.size();

        string ans = "";
        for(char ch : s){
            if(ch == '*' && ans.size() != 0) ans.pop_back();
            else ans.push_back(ch);
        }
        return ans;
        
    }
};