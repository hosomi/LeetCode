class Solution {
public:
    int numOfArrays(int n, int m, int k) {

        for (int i = 0; i <= m; i++) {
            dp[1][i][1] = 1;
            pre[1][i][1] = i;
        }
        
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                for (int l = 1; l <= k; l++) {
                    dp[i][j][l] = (1LL * j * dp[i-1][j][l]) % mod;
                    dp[i][j][l] = (dp[i][j][l] + pre[i-1][j-1][l-1]) % mod;
                    pre[i][j][l] = (pre[i][j-1][l] + dp[i][j][l]) % mod;
                }
            }
        }
        return pre[n][m][k];
    }

private:
    int dp[51][101][51];
    int pre[51][101][51];
    int mod = 1e9 + 7;
};
