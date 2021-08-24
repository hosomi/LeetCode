class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {

        int row = matrix.size();
        if (row == 0) {
            return 0;
        }

        int col = matrix[0].size();
        vector<vector<int>> v(row + 1, vector(col + 1, 0));
        int max = 0;
        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= col; j++) {
                if (matrix[i-1][j-1] == '0') {
                    continue;
                }
                v[i][j] = std::min({v[i - 1][j], v[i][j - 1], v[i - 1][j - 1]}) + 1;
                max = std::max(max, v[i][j]);
            }
        }
        return max * max;
    }
};
