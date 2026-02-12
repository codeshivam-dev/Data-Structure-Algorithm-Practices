class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int maxi = 0;

        for(int i = 0; i<n; i++){
            map<char, int> mp;
            for(int j = i; j<n; j++){
                mp[s[j]]++;
                if(checkEqual(mp, mp[s[j]])){
                    maxi = max(maxi, j - i + 1);
                }
            }
        }
        return maxi;
    }

    bool checkEqual(map<char,int>&mp, int fq){
        for(auto m: mp){
            if(m.second !=  fq) return false;
        }
        return true;
    }
};