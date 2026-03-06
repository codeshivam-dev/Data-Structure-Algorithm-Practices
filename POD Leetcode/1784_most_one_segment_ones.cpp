
class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.size();
        int segment = 0;

        for(int i=0; i<n; i++){
            if(s[i] == '1'){
                segment++;
                while(i < n && s[i] == '1') i++;
            }
        }

        return segment == 1;
    }
};