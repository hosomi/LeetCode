class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {

        int rowSize = board.size();
        int colSize = board[0].size();
        int x = 0;
        int y = 0;
        for (int i = 0; i < rowSize; i++) {
            for (int j = 0; j < colSize; j++) {
                if (board[i][j] == 'R') {
                    y = i;
                    x = j;
                }
            }
        }
        
        int cur = 0;
        char pos = '\0';
        string dirs = "rlud";
        int result = 0;
        for (int i = 0; i < dirs.size(); i++) {
            char dir = dirs[i];
            if (dir == 'r' or dir == 'l') {
                cur = x;
            } else if (dir == 'u' or dir == 'd') {
                cur = y;
            }

            while (cur >= 0 and cur < rowSize) {
                if (dir == 'r' or dir == 'l') {
                    pos = board[y][cur];
                } else if (dir == 'u' or dir == 'd') {
                    pos = board[cur][x];
                }

                if (pos=='p') {
                    result++;
                    break;
                } else if(pos=='B') {
                    break;
                }

                if (dir == 'r' or dir == 'd') {
                    cur++;
                } else if (dir == 'l' or dir == 'u') {
                    cur--;
                }
            }
        }
        
        return result;
    }
};
