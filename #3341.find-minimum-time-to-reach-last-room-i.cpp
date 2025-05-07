class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {

        int n = moveTime.size();
        int m = moveTime[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({0, 0, 0});
        dist[0][0] = 0;
        vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        while (!pq.empty()) {
            auto curr = pq.top(); pq.pop();
            int time = curr[0], row = curr[1], col = curr[2];
            if (time > dist[row][col]) continue;
            for (auto d : dirs) {
                int nrow = row + d.first, ncol = col + d.second;
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                    int ntime = max(time, moveTime[nrow][ncol]) + 1;
                    if (ntime < dist[nrow][ncol]) {
                        dist[nrow][ncol] = ntime;
                        pq.push({ntime, nrow, ncol});
                    }
                }
            }
        }
        
        return dist[n - 1][m - 1];
    }
};
