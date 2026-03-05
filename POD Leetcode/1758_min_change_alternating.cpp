class Solution {
public:
    int minOperations(string s) {
        int st_zero = 0;
        int st_one = 0;
        for(int i = 0; i<s.size(); i++){
            // when correct string start from zero
            if(i%2==0 && s[i] == '1') st_zero++;
            else if(i%2 == 1 && s[i] == '0') st_zero++;

            // when correct or final string start from one
            if(i%2==0 && s[i] == '0') st_one++;
            else if(i%2 == 1 && s[i] == '1') st_one++;

        }

        return min(st_zero, st_one);
    }
};