class Solution {
public:
    int minDays(vector<vector<int>>& grid) {
        
        rows = grid.size();
        cols = grid[0].size();
        if (disconnected(grid)) {
            return 0;
        }

        for (int x = 0; x < rows; x++) {
            for (int y = 0; y < cols; y++) {
                if (!grid[x][y]) {
                    continue;
                }

                grid[x][y] = 0;
                if (disconnected(grid)) {
                    return 1;
                }

                grid[x][y] = 1;
            }
        }
        return 2;
    }

private:
    int rows, cols;
    vector<pair<int, int>> directions= {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    void dfs(int r, int c,
        vector<vector<int>>& grid, vector<vector<int>> &vis) {

        vis[r][c] = 1;
        for (auto it : directions) {
            int dr = r + it.first;
            int dc = c + it.second;
            if (dr < 0 || dc < 0 || dr >= rows || dc >= cols
                || vis[dr][dc] || !grid[dr][dc]) {
                continue;
            }
            dfs(dr, dc, grid, vis);
        }
    }

    bool disconnected(vector<vector<int>>& grid) {

        int components = 0;
        vector<vector<int>> vis(rows, vector<int> (cols,0));
        for (int x = 0; x < rows; x++) {
            for (int y = 0; y < cols; y++) {
                if (grid[x][y] && !vis[x][y]) {
                    dfs(x, y, grid, vis);
                    components++;
                    if (components > 1 || components == 0) {
                        return true;
                    }
                }
            }
        }
        return (components > 1 || components == 0);
    }
};
