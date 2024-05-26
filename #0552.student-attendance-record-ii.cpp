class Solution {
public:
    int checkRecord(int n) {

        vector<vector<long long>> dp(2, vector<long long> (6, 0));
        int mod = 1e9 + 7;
        dp[0][0] = 1;
        dp[0][1] = 1;
        dp[0][5] = 1;
        for (int i = 1; i < n; i++) {
            dp[i  %2][0] = (dp[(i - 1) % 2][0] + dp[(i - 1) % 2][1] 
                + dp[(i - 1) % 2][2] + dp[(i - 1) % 2][3]
                + dp[(i - 1) % 2][4] + dp[(i - 1) % 2][5]) % mod;

            dp[i % 2][2] = (dp[(i - 1) % 2][0]);
            dp[i % 2][3] = (dp[(i - 1) % 2][1]);
            dp[i % 2][5] = (dp[(i - 1) % 2][1] + dp[(i-1) % 2][3]
                + dp[(i - 1) % 2][5]) % mod;
            dp[i % 2][4] = (dp[(i - 1) % 2][2]);
            dp[i % 2][1] = (dp[(i - 1) % 2][5]);
        }
        return (dp[(n - 1) % 2][0] + dp[(n - 1) % 2][1]
            + dp[(n - 1) % 2][2] + dp[(n - 1) % 2][3]
            + dp[(n - 1) % 2][4] + dp[(n - 1) % 2][5]) % mod;
    }
};
