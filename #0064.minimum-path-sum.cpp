class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        int rowSize = grid.size();
        if (rowSize == 0) {
            return 0;
        }

        int colSize = grid[0].size();
        int x;
        int y;
        for (int i = 0; i < rowSize; i++) {
            for (int j = 0; j < colSize; j++) {
                x = (i - 1 >= 0) ? grid[i - 1][j] : INT_MAX;
                y = (j - 1 >= 0) ? grid[i][j - 1] : INT_MAX;
                grid[i][j] += (std::min(x, y) == INT_MAX) ? 0 : std::min(x, y);
            }
        }
        
        return grid[rowSize - 1][colSize - 1];
    }
};
