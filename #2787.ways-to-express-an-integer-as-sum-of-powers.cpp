class Solution {
public:
    int numberOfWays(int n, int x) {

        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        vector<int> d;
        d.push_back(-1);
        
        for (int i = 1; i <= n; i++) {
            long long cnt = 1;
            for (int j = 0; j < x; j++) {
                cnt = cnt * i;
            }
            
            if (cnt <= n) {
                d.push_back(cnt);
            }
        }
        
        for (int i = 0; i < d.size(); i++) {
            dp[0][i] = 1;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < d.size(); j++) {
                dp[i][j] = dp[i][j - 1];
                if (i - d[j] >= 0) {
                    dp[i][j] = (dp[i][j] + dp[i - d[j]][j - 1]) % (int)(1e9 + 7);
                }
            }
        }
        return dp[n][d.size() - 1];
    }
};
