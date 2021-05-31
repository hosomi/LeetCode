class Solution {
public:
    void solve(vector<vector<char>>& board) {

        int row = board.size();
        int col = board[0].size();    
        function<void(int, int)> dfs = [&](int x, int y) {
            if (x < 0 || x >= col || y < 0 || y >= row || board[y][x] != 'O') {
                return;
            }

            board[y][x] = '-';   
            dfs(x - 1, y);
            dfs(x + 1, y);
            dfs(x, y - 1);
            dfs(x, y + 1);
        };

        for (int y = 0; y < row; ++y) {
            dfs(0, y), dfs(col - 1, y);
        }

        for (int x = 0; x < col; ++x) {
            dfs(x, 0), dfs(x, row - 1);
        }

        map<char, char> m{{'-','O'},{'O','X'}, {'X','X'}};
        for (int y = 0; y < row; ++y) {
            for (int x = 0; x < col; ++x) {
                board[y][x] = m[board[y][x]];
            }
        }
    }
};
