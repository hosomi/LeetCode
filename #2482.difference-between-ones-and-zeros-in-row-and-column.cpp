class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {

        int row = grid.size();
        int col = grid[0].size();
        vector<int> row1(row ,0);
        vector<int> col1(col ,0);
        for (int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    row1[i]++;
                    col1[j]++;
                }
            }
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                grid[i][j] = (row1[i] + col1[j])
                    - (row + col - row1[i] - col1[j]);
            }
        }
        return grid;
    }
};
