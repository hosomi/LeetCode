class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {

		int m = heightMap.size();
		int n = heightMap[0].size();
        priority_queue<pair<int, pair<int, int>>> pq;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0 || i == m - 1 || j == n - 1) {
                    pq.push({(-1)*heightMap[i][j], {i, j}});
                    vis[i][j] = true;
                }
            }
        }
        
        int dx[4] = {-1, 0, 0, 1};
        int dy[4] = {0, -1, 1, 0};
        int res = 0;
        while (!pq.empty()) {
            int h = (-1) * pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            for (int k = 0; k < 4; k++) {
                int i = x + dx[k];
                int j = y + dy[k];
                if (isValid(i, m) && isValid(j, n) && !vis[i][j]) {
                    vis[i][j] = true;
                    res += std::max(0, h - heightMap[i][j]);
                    int max = std::max(h, heightMap[i][j]);
                    pq.push({(-1) * max, {i, j}});
                }
            }
        }
        return res;
    }

private:
    bool isValid(int index, int lim) {
        return (index >= 0 && index < lim);
    }  
};
