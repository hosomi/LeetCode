class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dis(n, vector<int>(m, INT_MAX));
        vector<vector<int>>vis(n, vector<int>(m, 0));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};
        pq.push({grid[0][0], 0, 0});
        dis[0][0] = grid[0][0];
        vis[0][0] = 1;
        while (!pq.empty()) {
            int d = pq.top()[0];
            int r = pq.top()[1];
            int c = pq.top()[2];
            pq.pop();
            vis[r][c] = 1;
            for (int k = 0; k < 4; k++) {
                int nr = r + drow[k];
                int nc = c + dcol[k];
                if (nr < n 
                    && nc < m 
                    && nr >= 0 
                    && nc >= 0 
                    && !vis[nr][nc] 
                    && d + grid[nr][nc] < dis[nr][nc]) {
                    dis[nr][nc] = d + grid[nr][nc];
                    pq.push({dis[nr][nc], nr, nc});
                }
            }
        }
        return dis[n - 1][m - 1];
    }
};
