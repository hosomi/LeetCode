class Solution {
public:
    int minCost(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n,1e9)), vis(m,vector<int>(n,0));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        int dx[5] = {0, 0, 0, 1, -1}, dy[5] = {0, 1, -1, 0, 0};
        pq.push({0,{0,0}});
        dist[0][0]=0;
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int x = it.second.first;
            int y = it.second.second; 
            int cost = it.first;
            if (vis[x][y]) {
                continue;
            }

            vis[x][y] = 1;
            for (int i = 1; i <= 4; i++) {
                int x2 = x + dx[i];
                int y2 = y + dy[i]; 
                if (x2 < 0 || y2 < 0 || x2 >= m || y2 >= n) {
                    continue;
                }

                if (grid[x][y] == i) {
                    if (dist[x2][y2] >= cost) { 
                        dist[x2][y2] = cost;
                        pq.push({cost, {x2, y2}});
                    }
                } else { 
                    if (dist[x2][y2] >= cost + 1) {
                        dist[x2][y2] = cost + 1;
                        pq.push({cost + 1, {x2, y2}});
                    }
                }
            }
        }

        return dist[m - 1][n - 1];
    }
};
