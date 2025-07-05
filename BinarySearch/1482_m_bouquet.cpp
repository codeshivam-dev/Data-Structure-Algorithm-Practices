class Solution {
public:
    int findBouquet(vector<int>& bloomDay, int day, int k){
        int cnt = 0;
        int bouquet = 0;
        for(int bloom : bloomDay){
            if(bloom <= day){
                cnt++;
            }
            else{
                bouquet += cnt/k;
                cnt = 0;
            }
        }
        bouquet += cnt/k;
        return bouquet;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        // if(n < long long(m*k)) return -1;

        int low = 1, high = *max_element(begin(bloomDay), end(bloomDay));
        int ans = -1;

        while(low <= high){
            int day = low + (high - low)/2;

            int bouquet = findBouquet(bloomDay,day, k); 

            if(bouquet >= m){
                ans = day;
                high = day - 1;
            }
            else low = day + 1;
        }
        return ans;
    }
};