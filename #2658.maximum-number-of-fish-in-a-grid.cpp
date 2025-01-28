class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {

        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                ans= std::max(ans, f(i, j, grid));
            }
        }
        return ans;
    }

private:
    int f(int i, int j, vector<vector<int>>& grid) {

        if (i < 0 || j < 0
            || i >= grid.size()
            || j >= grid[0].size()
            || grid[i][j] == 0
            || grid[i][j] == -1) {
                return 0;
        }

        int ans = grid[i][j];
        grid[i][j]=-1;
        ans += f(i + 1, j, grid)
            + f(i - 1, j, grid)
            + f(i, j - 1, grid)
            + f(i, j + 1, grid);
        return ans;
    }
};
