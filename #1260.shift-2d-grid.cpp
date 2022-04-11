class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {

        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> result(row, vector<int>(col, 0));
        for (int i = 0 ; i < row; i++) {
            for (int j = 0; j < col; j++) {
                result[(i + (j + k) / col) % row][(j + k)%col] = grid[i][j];
            }
        }
        return result;
    }
};
