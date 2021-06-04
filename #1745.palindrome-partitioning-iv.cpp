class Solution {
public:
    bool checkPartitioning(string s) {

        int size = s.size();
        vector<vector<int>> board = vector<vector<int>>(size + 10, vector<int>(size + 10));
        for (int i = 0; i < size; i++) {
            board[i][i] = 1;
        }

        int left;
        int right;
        for (int i = 0; i < size - 1; i++) {
            left = i - 1;
            right = i + 1;
            while (left >= 0 && right < size && s[left] == s[right]) {
                board[left][right] = 1;
                left--;
                right++;
            }

            left = i - 1;
            right = i + 2;
            if (s[i] == s[i + 1]) {
                board[i][i + 1] = 1;
            }

            while (left >= 0 && right < size
                   && s[left] == s[right]
                   && s[i] == s[i + 1]) {

                board[i][i + 1] = 1;
                board[left][right] = 1;
                left--;
                right++;
            }
        }

        for (int i = 0; i < size;i++) {
            for (int j = i + 1; j < size; j++) {
                if (board[0][i]
                    && board[i + 1][j]
                    && board[j + 1][size - 1]) {

                    return true;
                }
            }
        }
        return false;
    }
};
