class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int comb = 1 << k;

        unordered_set<string>st;

        for(int i = k; i <= s.size(); i++){
            string tm = s.substr(i-k, k);
            
            if(!st.count(tm)) st.insert(tm);

            if(st.size() == comb) return true;
        }
        return false;
    }
};