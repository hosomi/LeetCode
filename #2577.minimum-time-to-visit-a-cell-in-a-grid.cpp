class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {

        if (grid[0][1] > 1 && grid[1][0] > 1) {
            return -1;
        }

        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        vector<int> dirX = {0, 0, 1, -1};
        vector<int> dirY = {1, -1, 0, 0};
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

        pq.emplace(0, 0, 0);
        dist[0][0] = 0;
        while (!pq.empty()) {
            auto [time, x, y] = pq.top();
            pq.pop();

            if (x == n - 1 && y == m - 1) {
                return time;
            }

            for (int i = 0; i < 4; i++) {
                int newX = x + dirX[i];
                int newY = y + dirY[i];

                if (newX >= 0 && newX < n && newY >= 0 && newY < m) {
                    int newTime = time + 1; 
                    if (grid[newX][newY] > newTime) {
                        newTime = grid[newX][newY] + (grid[newX][newY] % 2 == dist[x][y] % 2);
                    }
  
                    if (newTime < dist[newX][newY]) {
                        dist[newX][newY] = newTime;
                        pq.emplace(newTime, newX, newY);
                    }
                }
            }
        }
        return -1;
    }
};
