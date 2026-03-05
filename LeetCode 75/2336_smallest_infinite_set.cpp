class SmallestInfiniteSet {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    unordered_set<int> st;   // avoid duplicates
    int cnt = 1;

    SmallestInfiniteSet() {
        pq.push(cnt);
        st.insert(cnt);
        cnt++;
    }
    
    int popSmallest() {
        int top = pq.top();
        pq.pop();
        st.erase(top);

        if(pq.empty()) {
            pq.push(cnt);
            st.insert(cnt);
            cnt++;
        }

        return top;
    }
    
    void addBack(int num) {
        if(num < cnt && st.find(num) == st.end()) {
            pq.push(num);
            st.insert(num);
        }
    }
};