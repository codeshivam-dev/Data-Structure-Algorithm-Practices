class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
        int l = flowerbed.length;

        if (l == 1) {
            if (flowerbed[0] == 0) return n <= 1;
            return n == 0;
        }
        
        for (int i = 0; i < l; i++) {

            if (flowerbed[i] == 1) continue;

            if (i == 0) { 
                if (l == 1 || flowerbed[i + 1] == 0) {
                    n--;
                    i++;
                }
            }
            else if (i == l - 1) { 
                if (flowerbed[i - 1] == 0) {
                    n--;
                }
            }
            else if (flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0) {
                n--;
                i++;
            }

            if (n <= 0) return true;
        }
        return false;
    }
}
