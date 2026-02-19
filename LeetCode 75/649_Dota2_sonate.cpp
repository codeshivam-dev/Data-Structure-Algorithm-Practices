class Solution {
public:
    int n;

    // This function finds the next active senator of opposite party
    // starting from idx (circularly) and marks him as removed.
    void removedSenator(string& senate, vector<bool>& removed, int idx, char ch){
        while(true){
            // If we find a senator of opposite party who is not removed
            if(senate[idx] == ch && removed[idx] == false){
                removed[idx] = true;   // ban that senator
                break;
            }
            // move circularly
            idx = (idx + 1) % n;
        }
    }

    string predictPartyVictory(string senate) {
        n = senate.size();

        int r_count = 0, d_count = 0;
        vector<bool> removed(n, false); // track banned senators

        // Count initial senators of each party
        for (char ch : senate) {
            if (ch == 'D')
                d_count++;
            else
                r_count++;
        }

        int idx = 0;

        // Continue rounds until one party is eliminated
        while (r_count > 0 && d_count > 0) {

            // Skip if this senator is already banned
            if (removed[idx] == false) {

                if (senate[idx] == 'R') {
                    // Radiant bans next available Dire
                    removedSenator(senate, removed, (idx + 1) % n, 'D');
                    d_count--;
                }
                else {
                    // Dire bans next available Radiant
                    removedSenator(senate, removed, (idx + 1) % n, 'R');
                    r_count--;
                }
            }

            // move to next senator (circular order)
            idx = (idx + 1) % n;
        }

        return r_count == 0 ? "Dire" : "Radiant";
    }
};
