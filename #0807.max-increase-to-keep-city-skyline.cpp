class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {

        int row = grid.size();
        int col = grid[0].size();
        vector<int> rows = vector<int>((int)row, 0);
        vector<int> cols = vector<int>((int)col, 0);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                rows[i] = std::max(grid[i][j], rows[i]);
                cols[j] = std::max(grid[i][j], cols[j]);
            }
        }
        
        int result = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                result += std::min(cols[i], rows[j]) - grid[i][j];
            }
        }
        return result;
    }
};
