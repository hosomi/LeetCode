class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {

        if (n == 1) {
            return { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        }
        
        queue<int> q;
        for (int i = 1; i <= 9; ++i) {
            q.push(i);
        }
        
        int order = 1;
        vector<int> result;
        while(order <= n){
            int size = q.size();  
            while(size-- > 0) {
                int cur = q.front();
                q.pop();
                if (order == n) {
                    result.push_back(cur);
                    continue;
                }

                int d = cur % 10;
                if (d - k >= 0) {
                    q.push(cur * 10 + (d - k));
                }

                if (k != 0 && d + k <= 9) {
                    q.push(cur * 10 + (d + k));
                }
            }
            ++order;
        }
        return result;
    }
};
