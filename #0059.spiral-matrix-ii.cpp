class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {

        vector<vector<int>> result(n, vector<int>(n, 0));
        vector<int> board = {0, 1, 0, -1, 0};
        int index = 0;
        int row = 0;
        int col = 0;
        int value = 1;
        while (value <= n * n) {
            result[row][col] = value++;
            if (result[(row + n + board[index])%n][(col + n + board[index + 1]) %n] != 0) {
                index = (index+1) % 4;
            }
            row += board[index];
            col += board[index+1];
        }
        return result;
    }
};
