class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        recursive(board, 0, 0);
    }

private:
    bool recursive(vector<vector<char>>& board, int row, int col) {

        for (int i = row; i < 9; ++i, col = 0) {
            for (int j = col; j < 9; ++j) {
                if (board[i][j] != '.') {
                    continue;
                }

                for (char d = '1'; d <= '9'; ++d) {
                    if(!isValid(board, i, j, d)) {
                        continue;
                    }
                    board[i][j] = d;
                    if (recursive(board, i, j + 1)) {
                        return true;
                    }
                    board[i][j] = '.';
                }
                return false;
            }
        }
        return true;
    };

    bool isValid(vector<vector<char>>& board, int row, int col, char c) {

        for (int i = 0; i < 9; ++i) {
            if (board[i][col] == c) {
                return false;
            }
            if( board[row][i] == c) {
                return false;
            }
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) {
                return false;
            }
        }
        return true;
    };
};
