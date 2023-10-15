class Solution {
public:
    int numWays(int steps, int arrLen) {

        if (arrLen == 1) {
            return 1;
        }

        const int MOD = (int) 1e9 + 7;
        int n = std::min(arrLen, steps / 2 + 1);
        vector<int> dp(n);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= steps; i++) {
            vector<int> new_dp(n); 
            for (int j = 0; j < n; j++) {
                new_dp[j] = ((dp[j] + (0 < j ?
                    dp[j - 1] : 0)) % MOD + (j + 1 < n ?
                    dp[j + 1] : 0)) % MOD
                ;
            }
            std::swap(dp, new_dp);
        } 
        return dp[0];
    }
};
