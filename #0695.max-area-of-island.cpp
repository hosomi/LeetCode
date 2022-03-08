class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int size = grid.size();
        int col = grid[0].size();
        int result = 0;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < col; j++) {
                result = max(result, maxAreaOfIsland(grid, i, j));
            }
        }
        return result;
    }

private:

    int maxAreaOfIsland(vector<vector<int>>& grid, int i, int j) {

        if (i < 0 || j < 0 || i >= grid.size()
            || j >= grid[0].size() || grid[i][j] == 0) {
            return 0;
        }

        int result = 1;
        grid[i][j] = 0;
        int k[4] = { 0, 0, 1, -1 };
        int l[4] = { 1, -1, 0, 0 };
        for (int index = 0; index < 4; index++) {
            int m = i + k[index];
            int n = j + l[index];
            result += maxAreaOfIsland(grid, m, n);
        }
        return result;
    }
};
