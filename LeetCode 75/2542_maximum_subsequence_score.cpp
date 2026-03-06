// Sort      -> O(n log n)
// Heap ops  -> O(n log k)
// Total     -> O(n log n)

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        
        // pair bana diya taaki nums1 aur nums2 relation maintain rahe
        vector<pair<int,int>> vec(n);

        for(int i =0; i<n; i++){
            vec[i] = {nums1[i], nums2[i]};
        }

        // Greedy Step:
        // nums2 ko descending sort kar diya
        // taki jab hum index i par ho, vec[i].second current minimum nums2 ho
        sort(vec.begin(), vec.end(), [&](auto P1, auto P2){
            return P1.second > P2.second;
        });

        // min heap maintain karega k largest nums1 values
        priority_queue<int, vector<int>, greater<int>> pq;

        long long kSum = 0;

        // pehle k elements leke initial subsequence bana li
        for(int i = 0; i<=k-1; i++){ 
            kSum += vec[i].first;
            pq.push(vec[i].first);
        }

        // initial score
        // minimum nums2 = vec[k-1].second
        long long result = kSum * vec[k-1].second;

        // remaining elements explore karte hain
        for(int i = k; i<n; i++){

            // smallest nums1 remove kar diya
            // kyunki hum larger nums1 prefer karte hain
            kSum -= pq.top();
            pq.pop();

            // new nums1 add
            kSum += vec[i].first;
            pq.push(vec[i].first);

            // current nums2 minimum hai
            result = max(result, kSum * vec[i].second);
        }

        return result;
    }
};

