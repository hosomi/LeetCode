class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m, 0));
        int result = 0;
        for (int c = m - 2; c >= 0; c--) {
            for (int r = 0; r < n;r++) {
                if (c + 1 < m && grid[r][c + 1] > grid[r][c]) {
                    dp[r][c] = std::max(dp[r][c], 1 + dp[r][c + 1]);
                }

                if (r - 1 >= 0 && c + 1 < m && grid[r-1][c+1] > grid[r][c]) {
                    dp[r][c] = std::max(dp[r][c], 1 + dp[r - 1][c + 1]);
                }

                if (r + 1 < n && c + 1 < m && grid[r+1][c+1] > grid[r][c]){
                    dp[r][c] = std::max(dp[r][c],1+dp[r + 1][c + 1]);
                }

                if (c == 0) {
                    result = std::max(result, dp[r][c]);
                }
            }
        }     
        return result;
    }
};
