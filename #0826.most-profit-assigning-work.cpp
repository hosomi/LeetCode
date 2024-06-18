class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {

        priority_queue<pair<int,int>> pq;
        for (int i = 0; i < profit.size(); i++) {
            pq.push({profit[i], difficulty[i]});
        }

        std::sort(worker.begin(), worker.end());

        int i = worker.size() - 1;
        int result = 0;
        while (i >= 0 && !pq.empty()) {
            if (worker[i] >= pq.top().second) {
                result+=pq.top().first;
                i--;
                continue;
            }

            pq.pop();
        }
        return result;
    }
};
