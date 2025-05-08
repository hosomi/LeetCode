class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {

        int n = moveTime.size();
        int m = moveTime[0].size();
        priority_queue<tuple<long, int, int, int>, vector<tuple<long, int, int, int>>, greater<>> pq;
        pq.push({0, 1, 0, 0});
        const vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        vector<vector<long>> minTime(n, vector<long>(m, LONG_MAX));
        while (pq.size()) {
            auto [cur_t, step, x, y] = pq.top();
            pq.pop();

            if (x == n - 1 && y == m - 1) {
                return cur_t;
            }

            for (auto &dir : dirs) {
                int nx = x + dir[0];
                int ny = y + dir[1];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
                    continue;
                }

                long new_t = std::max(cur_t + step, (long)moveTime[nx][ny] + step);
                if (new_t < minTime[nx][ny]) {
                    minTime[nx][ny] = new_t;
                    int new_step = step == 1 ? 2 : 1;
                    pq.push({new_t, new_step, nx, ny});
                }
            }
        }
        return -1;
    }
};
