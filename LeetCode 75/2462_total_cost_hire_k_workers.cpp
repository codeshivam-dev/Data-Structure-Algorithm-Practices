class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();

        priority_queue<int, vector<int>, greater<int>> first, last;

        long long sum = 0;
        int i = 0;
        int j = n - 1;

        // push first candidates
        while(i < candidates && i <= j){
            first.push(costs[i]);
            i++;
        }

        // push last candidates
        while(j >= n - candidates && i <= j){
            last.push(costs[j]);
            j--;
        }

        while(k--){
            
            if(last.empty() || (!first.empty() && first.top() <= last.top())){
                
                sum += first.top();
                first.pop();

                if(i <= j){
                    first.push(costs[i]);
                    i++;
                }
            }
            else{
                sum += last.top();
                last.pop();

                if(i <= j){
                    last.push(costs[j]);
                    j--;
                }
            }
        }

        return sum;
    }
};