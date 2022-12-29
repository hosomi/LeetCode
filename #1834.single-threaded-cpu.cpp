class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        
        int size = tasks.size();
        vector<pair<pair<int, int>, int>> pq1;
        for (int i = 0; i < size; i++) {
            pq1.push_back({{tasks[i][0], tasks[i][1]}, i});
        }

        std::sort(pq1.rbegin(), pq1.rend());
    
        priority_queue<pair<int, int>> pq2;
        long long task = 0;
        vector<int> result;
        while (not (pq1.empty() and pq2.empty())) {
            if (pq2.empty() and pq1.back().first.first > task) {
                task = pq1.back().first.first;
            }

            while (not pq1.empty() and pq1.back().first.first <= task) {
                pq2.push({-pq1.back().first.second, -pq1.back().second});
                pq1.pop_back();
            }

            if (not pq2.empty()) {
                task -= pq2.top().first;
                result.push_back(-pq2.top().second);
                pq2.pop();
            }
        }
        return result;
    }
};
