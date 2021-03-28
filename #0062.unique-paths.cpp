class Solution {
public:
    int uniquePaths(int m, int n) {

        vector<vector<int>> up(m + 1, vector(n + 1, 0));
        up[1][1] = 1;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == 1 && j == 1) {
                    continue;
                }
                up[i][j] = up[i-1][j] + up[i][j-1];
            }
        }
        return up[m][n];
    }
};
