class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {

        int rowSize = board.size();
        int colSize;
        for (int i = 0; i < rowSize; i++) {
            colSize = board[i].size();
            for (int j = 0; j < colSize; j++) {
                if (board[i][j] == word[0]) {
                    if (isSearchWord(board, word, 0, i, j)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

private:
    bool isSearchWord(vector<vector<char>> &board, string& word, int index, int row, int col) {

        int rowSize = board.size();
        if (row < 0 || row >= board.size()
            || col < 0 || col >= board[0].size()
            || board[row][col] != word[index]) {
            return false;
        }

        if (index + 1 == word.size()) {
            return true;
        }

        board[row][col] = '\0';
        if (isSearchWord(board, word, index+1, row+1, col)
            || isSearchWord(board, word, index+1, row-1, col)
            || isSearchWord(board, word, index+1, row, col+1)
            || isSearchWord(board, word, index+1, row, col-1)) {
            return true;
        }

        board[row][col] = word[index];
        return false;
    }
};
