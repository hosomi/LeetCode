class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {

        queue<Board> q;
        set<vector<vector<int>>> visited;
        vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        int i, j;
        for (i = 0; i < 2; i++) {
            auto it = find(board[i].begin(), board[i].end(), 0);
            if (it != board[i].end()) {
                j = it - board[i].begin();
                break;
            }
        }
        
        q.push(Board(board, i, j, 0));
        while (!q.empty()) {
            Board b = q.front(); q.pop();
            if (isSolved(b.board)) {
                return b.depth;
            }
            
            for (vector<int> dir : dirs) {
                int i2 = b.i + dir[0];
                int j2 = b.j + dir[1];
                if (i2 >= 0 && i2 < 2 && j2 >= 0 && j2 < 3) {
                    vector<vector<int>> newBoard = b.board;
                    swap(newBoard[b.i][b.j], newBoard[i2][j2]);
                    if (visited.insert(newBoard).second) {
                        q.push(Board(newBoard, i2, j2, b.depth + 1));
                    }
                }
            }
        }
        return -1;
    }

private:
    struct Board {
        vector<vector<int>> board;
        int i;
        int j;
        int depth;
        Board(vector<vector<int>> b, int i, int j, int d):
            board(b), i(i), j(j), depth(d) {};
    };

    bool isSolved(vector<vector<int>>& board) {

        if (board[1][2] != 0) {
            return false;
        }
        
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                if (!(i == 1 && j == 2)
                    && board[i][j] != i * 3 + (j+1)) {
                    return false;
                }
            }
        }
        return true;
    };
};
