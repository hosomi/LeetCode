class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {

        int row = grid.size();
        if (row == 0) {
            return 0;
        }

        int col = grid[0].size();
        if (col == 0) {
            return 0;
        }

        vector<vector<vector<int>>> matrix(2, vector<vector<int>>(col, vector<int>(col, INT_MIN)));
        matrix[0][0][col - 1] = grid[0][0] + grid[0][col - 1];
        for (int i = 1; i < row; i++) {
            for (int j = 0; j < col; j++){
                for (int k = 0; k < col; k++) {
                    for (int l = j - 1; l <= j + 1; l++) {
                        for (int m = k - 1; m <= k + 1; m++) {
                            if (l < 0 || l >= col || m < 0 || m >= col) {
                                continue;
                            }

                            matrix[i%2][j][k] = std::max(matrix[i%2][j][k],
                                ((j != k) ?
                                grid[i][j] + grid[i][k]
                                : grid[i][j]) + matrix[(i-1)%2][l][m]);
                        }
                    }
                }
            }
        }

        int result = 0;
        for (int i = 0; i < col; i++) {
            for (int j = 0; j < col; j++) {
                result = std::max(result, matrix[(row - 1) % 2][i][j]);
            }
        }
        return result;
    }
};
