class Solution {
    public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
        int n = candies.length;

        List<Boolean> arr = new ArrayList<>(n);
        int maxCandie = 0;
        for(int candie : candies){
            maxCandie = Math.max(maxCandie, candie);
        }
        for(int i = 0; i<n; i++){
            if(candies[i] + extraCandies >= maxCandie) arr.add(true);
            else arr.add(false);
        }
        return arr;
    }

}