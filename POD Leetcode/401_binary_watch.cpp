class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;

        // All possible hours (0 to 11)
        for (int i = 0; i <= 11; i++) {

            // All possible minutes (0 to 59)
            for (int j = 0; j <= 59; j++) {

                // Count total set bits in hour + minute
                // __builtin_popcount(x) gives number of 1s in binary of x
                if (__builtin_popcount(i) + __builtin_popcount(j) == turnedOn) {

                    // Build time string in "H:MM" format
                    string s = to_string(i);
                    s += ":";

                    // If minute < 10, add leading zero (e.g., 1:05)
                    if (j < 10) {
                        s += "0";
                        s += to_string(j);
                    }
                    else {
                        s += to_string(j);
                    }

                    ans.push_back(s); 
                }
            }
        }

        return ans;  
    }
};
