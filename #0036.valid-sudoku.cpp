class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        unordered_set<string> set;
        string work, col, cell, row;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    continue;
                }
                work = "(" + to_string(board[i][j]) + ")";
                row = to_string(i) + work;
                col = work + to_string(j);
                cell = to_string(i / 3) + work + to_string(j / 3);
                if (set.count(row) || set.count(col) || set.count(cell)) {
                    return false;
                }
                set.insert(row);
                set.insert(col);
                set.insert(cell);
            }
        }
        return true;
    }
};
