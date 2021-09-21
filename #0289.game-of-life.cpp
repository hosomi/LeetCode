class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {

        int row = board.size();
        int col = row ? board[0].size() : 0;
        int live;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                live = 0;
                for (int y = std::max(0, i - 1); y < std::min(row, i + 2); ++y) {
                    for (int x = std::max(0, j - 1); x < std::min(col, j + 2); ++x) {
                        live += board[y][x] & 1;
                    }
                }
                if (live == 3 || live - board[i][j] == 3) {
                    board[i][j] |= 0b10;
                }
            }
        }

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) { 
                board[i][j] >>= 1;
            }
        }
    }
};
