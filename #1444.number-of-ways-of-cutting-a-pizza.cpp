class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        
        int row = pizza.size();
        int col = pizza[0].size();
        vector<vector<int>> sums(row + 1, vector<int>(col + 1, 0));
        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= col; j++) {
                sums[i][j] = (pizza[i-1][j-1]=='A') + sums[i-1][j] +
                            sums[i][j-1] - sums[i-1][j-1];
            }
        }

        auto submatrixSum = [&](int x1, int y1, int x2, int y2) {
            return sums[x2][y2] - sums[x1][y2] - sums[x2][y1] + sums[x1][y1];
        };

        int memo[row][col][k];
        memset(memo, -1, sizeof memo);
        int div = 1e9 + 7;

        function<int(int,int,int)> solve = [&](int i, int j, int k) {
            if (k == 0) {
                return (int)(submatrixSum(i, j, row, col) > 0);
            }

            if (memo[i][j][k] != -1) {
                return memo[i][j][k];
            }

            int count = 0;
            for (int l = i + 1; l < row; l++) {
                if (submatrixSum(i, j, l, col) > 0) {
                    count = (count + solve(l, j, k-1)) % div;
                }
            }

            for (int l = j + 1; l < col; l++) {
                if (submatrixSum(i, j, row, l) > 0) {
                    count = (count + solve(i, l, k - 1)) % div;
                }
            }

            return memo[i][j][k] = count;
        };

        return solve(0, 0, k - 1);
    }
};
