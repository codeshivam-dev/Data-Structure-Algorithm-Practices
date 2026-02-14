class Solution {
public:
    int compress(vector<char>& arr) {
        int n = arr.size();

        int read = 0, write = 0;

        while(read < n){
            int current = arr[read];
            int cnt = 0;

            while(read < n && arr[read] == current) cnt++, read++;

            arr[write++] = current;

            if(cnt > 1){
                string s = to_string(cnt);
                for(char ch : s){
                    arr[write++] = ch;
                }
            }
        }
        return write;
    }
};