class Solution {
public:
    bool closeStrings(string word1, string word2) {
        
        // 1️⃣ First invariant: Length must be equal
        // Because we are only allowed to rearrange or swap frequencies,
        // we cannot add or delete characters.
        if(word1.size() != word2.size()) return false;

        // 2️⃣ Frequency arrays for 26 lowercase letters
        // Using array instead of map for O(1) access and clean comparison
        vector<int> f1(26, 0), f2(26, 0);

        // Count frequency of each character
        for(char c : word1) {
            f1[c - 'a']++;
        }

        for(char c : word2) {
            f2[c - 'a']++;
        }

        // 3️⃣ Second invariant: Character set must be same
        // If a character exists in word1 but not in word2,
        // rename operation cannot create a completely new character.
        for(int i = 0; i < 26; i++) {
            // XOR style check:
            // If one is zero and other is not → invalid
            if((f1[i] == 0) != (f2[i] == 0)) {
                return false;
            }
        }

        // 4️⃣ Third invariant: Frequency pattern must match
        // Since we can swap frequencies between characters,
        // we only care about multiset of counts, not which character has which count.
        sort(f1.begin(), f1.end());
        sort(f2.begin(), f2.end());

        // Final check: both frequency distributions must be identical
        return f1 == f2;
    }
};
