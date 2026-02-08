class Solution {
    public List<Long> mergeAdjacent(int[] nums) {
        int n = nums.length;
        if(n == 0) return new ArrayList<>();
        
        Stack<Long> stack = new Stack<>();

        for(int i = 0; i < n; i++){
            long curr_val = (long)nums[i];
            
            while(!stack.empty() && stack.peek() == curr_val){
                curr_val += stack.pop();
            }
            stack.push(curr_val);
        }

        return new ArrayList<>(stack);
    }
}