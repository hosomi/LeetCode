class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {

        if (grid.size() < 3 || grid[0].size() < 3) {
            return 0;
        }

        int result = 0;
        int row = grid.size() - 2;
        int col = grid[0].size() - 2;
        bool isBreak;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                isBreak = false;
                if (grid[i + 1][j + 1] != 5
                    || grid[i][j] == 5) {
                    continue;
                }

                if (grid[i][j] + grid[i + 2][j + 2] !=10
                   || grid[i + 2][j] + grid[i][j + 2] !=10
                   || grid[i + 1][j] + grid[i + 1][j + 2] != 10
                   || grid[i][j + 1] +grid[i + 2][j + 1] != 10) {
                    continue;
                }

                if (grid[i][j] + grid[i][j + 1] + grid[i][j + 2] != 15
                   || grid[i][j] + grid[i + 1][j] + grid[i + 2][j] != 15) {
                    continue;
                }

                for (int x =0; x < 3; x++) {
                    for (int y = 0; y < 3; y++) {
                        if (grid[i + x][j + y] > 9 || grid[i + x][j + y] < 0) {
                            isBreak = true;
                            break;
                        }
                    }
                }
                if (isBreak) {
                    continue;
                }
                result++;

            }
        }
        return result;
    }
};
