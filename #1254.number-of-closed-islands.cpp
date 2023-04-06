class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        
        row = grid.size();
        col = grid[0].size();
        int result = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (!grid[i][j]) {
                    if (dfs(grid, i, j)) {
                        result++;
                    }
                }
            }
        }
        return result;
    }

private:
    int row;
    int col;
    bool dfs(vector<vector<int>> &grid, int i, int j) {

        if (i < 0 || j < 0
            || i >= row || j >= col) {
            return false;
        }

        if (grid[i][j]) {
            return true;
        }

        grid[i][j] = 1;
        return dfs(grid, i + 1, j) 
            & dfs(grid, i - 1, j)
            & dfs(grid, i, j + 1)
            & dfs(grid, i, j - 1);
    }
};
