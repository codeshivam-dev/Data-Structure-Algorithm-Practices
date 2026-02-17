class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();

        unordered_map<int,int>mp;
        for(int num : arr) mp[num]++;

        set<int>st;
        for(auto it : mp) st.insert(it.second);

        return st.size() == mp.size();
    }
};