class Solution {
    public int minimumDeletions(String s) {

        int dp = 0;      // min deletions till now
        int countB = 0; // kitne 'b' aa chuke

        for (char ch : s.toCharArray()) {

            if (ch == 'b') {
                countB++; // future ke liye count
            } 
            else { // ch == 'a'

                // ya to is 'a' ko hatao
                // ya saare pehle ke 'b' hatao
                dp = Math.min(dp + 1, countB);
            }
        }

        return dp;
    }
}
