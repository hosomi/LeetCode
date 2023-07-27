class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        
        priority_queue<int> pq(batteries.begin(), batteries.end());
        long long sum = 0;
        for (int &batterie : batteries) {
            sum += batterie;
        }

        while (not pq.empty() && n != 1
            && pq.top() > sum / n) {
            sum -= pq.top();
            pq.pop();
            n--;
        }
        return sum / n;
    }
};
