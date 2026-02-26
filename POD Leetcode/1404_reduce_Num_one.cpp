class Solution {
public:
    int numSteps(string s) {
        int n = s.size();
        int steps = 0;
        int carry = 0;

        // Traverse from last bit to index 1
        for(int i = n - 1; i > 0; i--) {

            int bit = (s[i] - '0') + carry;

            if(bit % 2 == 0) {
                // even → divide by 2
                steps += 1;
            }
            else {
                // odd → add 1 + divide
                steps += 2;
                carry = 1;
            }
        }

        // If carry still present
        if(carry == 1) {
            steps += 1;
        }

        return steps;
    }
};