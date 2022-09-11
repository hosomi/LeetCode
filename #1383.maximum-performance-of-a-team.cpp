class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {

        vector<pair<int, int>> eff;
        for (int i = 0; i < n; i++) {
            eff.push_back({efficiency[i], speed[i]});
        }

        std::sort(eff.rbegin(), eff.rend());

        long second = 0;
        long result = 0;
        priority_queue <int, vector<int>, greater<int> > pq;
        for (int i = 0; i < n; i++) {
            pq.push(eff[i].second);
            second += eff[i].second;
            if (pq.size() > k) {
                second -= pq.top();
                pq.pop();
            }
            result = std::max(result, second * eff[i].first);
        }
        return result % (int)(1e9+7);
    }
};
