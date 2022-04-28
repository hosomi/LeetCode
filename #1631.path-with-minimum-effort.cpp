class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int row = heights.size();
        int col = heights[0].size();
        const auto dirs = vector<pair<int,int>>{{0,1}, {0, -1}, {-1, 0}, {1, 0}};
        auto visited = vector(row, vector(col, false));
        priority_queue<tuple<int,int,int>> q;
        q.push(tuple{0, 0, 0});
        while (!q.empty()) {
            const auto [eff, i, j] = q.top();
            q.pop();
            if (visited[i][j]) {
                continue;
            }
    
            visited[i][j] = true;
            if (i == row - 1 && j == col - 1) {
                return -eff;
            }

            for (auto [di, dj] : dirs) {
                int x = i + di;
                int y = j + dj;
                if (x < 0 || x >= row || y < 0 || y >= col || visited[x][y]) {
                    continue;
                }
    
                auto min = std::min(eff, - std::abs(heights[x][y] - heights[i][j]));
                q.push(tuple{min, x, y});
            }
        }
        return -1;    
    }
};
