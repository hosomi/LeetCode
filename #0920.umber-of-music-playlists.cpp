class Solution {
public:
    int numMusicPlaylists(int n, int goal, int k) {

        vector<vector<int>> dp(goal + 1,
            vector<int>(n + 1, 0));
        dp[0][0] = 1;
        for(int i = 1; i <= goal; ++i) {
            for (int j = 1; j <= n; ++j) {
                long x = 0;
                if (j <= i) {
                    x = ((long)n - j + 1) * dp[i-1][j - 1];
                }

                if (j > k) {
                    x += ((long)j - k) * dp[i - 1][j];
                }

                dp[i][j] = x % 1000000007;
            }
        }
        return dp[goal][n];
    }
};
