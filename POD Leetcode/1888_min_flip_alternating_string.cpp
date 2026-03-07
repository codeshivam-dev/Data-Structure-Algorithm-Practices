class Solution {
public:
    int minFlips(string s) {
        int n = s.size();

        int result = INT_MAX;
        int flip1 = 0, flip2 = 0;
        int  i = 0, j = 0;

       // sliding window
       while(j < 2*n){
        char expectedCharS1 = (j%2)?'1':'0'; // '010101..'
        char expectedCharS2 = (j%2)?'0':'1'; // '101010...'
        
        if(s[j%n] != expectedCharS1){ // j%n for circular
            flip1++;
        }

        if(s[j%n] != expectedCharS2){
            flip2++;
        }
        
        // window size exceeded -> slide window
        if(j-i+1 > n){
            expectedCharS1 = (i%2)?'1':'0';
            expectedCharS2 = (i%2)?'0':'1';

            if(s[i%n] != expectedCharS1) flip1--;
            if(s[i%n] != expectedCharS2) flip2--;

            i++;
        }

        if(j-i+1 == n) {
            result = min({result, flip1, flip2});
        }

        j++;
       }

       return result;
    }
};