class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {

        int index = 0;
        int sx;
        int sy; 
        m = grid.size();
        n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    ++index;
                } else if (grid[i][j] == 1) {
                    sx = i, sy = j;
                }
            }
        }
        return depthFirstSearch(grid, sx, sy, index);
    }

private:
    int m;
    int n;

    int depthFirstSearch(vector<vector<int>>& g, int i, int j, int index) {

        if (i < 0 || i >= m || j < 0 || j >= n || g[i][j] == -1) {
            return 0;
        }

        if (g[i][j] == 2) {
            return index <= 0 ? 1 : 0;
        }

        int temp = g[i][j];
        if (temp == 0) {
            index -= 1;
        }

        g[i][j] = -1;
        int paths = depthFirstSearch(g, i + 1, j, index)
            + depthFirstSearch(g, i - 1, j, index)
            + depthFirstSearch(g, i, j + 1, index)
            + depthFirstSearch(g, i, j - 1, index)
        ;
        g[i][j] = temp;
        return paths;
    }
};
