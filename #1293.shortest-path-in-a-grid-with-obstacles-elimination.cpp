class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {

        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> visited(row, vector<int>(col, -1));
        queue<vector<int>> q;
        q.push({0, 0, 0, k});
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            int x = t[0], y = t[1];
            if (x < 0 || x >= row || y < 0 || y >= col) {
                continue;
            }
            
            if (x == row - 1 && y == col - 1) {
                return t[2];
            }
             
            if (grid[x][y] == 1) {
                if (!(t[3] > 0)) {
                    continue;
                }
                
                t[3]--;
            }
            
            if (visited[x][y] != -1 && visited[x][y] >= t[3]) {
                continue;
            }
            
            visited[x][y] = t[3];
            q.push({x + 1, y, t[2] + 1, t[3]});
            q.push({x - 1, y, t[2] + 1, t[3]});
            q.push({x, y + 1, t[2] + 1, t[3]});
            q.push({x, y - 1, t[2] + 1, t[3]});
        }
        
        return -1;
    }
};
