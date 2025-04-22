class Solution {
public:
    int idealArrays(int n, int maxValue) {

        const int maxgroups = min(15, n + 1);
        vector<vector<int>> groups_dp(maxgroups, vector<int>(n+1));
        groups_dp[0][0] = 1;
        for (int g = 1; g < maxgroups; ++g) {
            int sum = groups_dp[g - 1][0];
            for (int i = 1; i <= n; ++i) {
                groups_dp[g][i] = sum;
                add(sum, groups_dp[g - 1][i]);
            }
        }

        int ans = 0;
        vector<vector<int>> chains(maxgroups, vector<int>(maxValue+1));
        for (int i = 1; i <= maxValue; ++i) {
            chains[1][i] = 1;
        }

        for (int g = 2; g < maxgroups; ++g) {
            for (int i = 1; i <= maxValue; ++i) {
                if (chains[g - 1][i] == 0) {
                    continue;
                }
                
                for (int m = 2 * i; m <= maxValue; m += i) {
                    add(chains[g][m], chains[g - 1][i]);
                }
            }
        }

        for (int g = 1; g < maxgroups; ++g) {
            for (int i = 1; i <= maxValue; ++i) {
                add(ans, (long long) chains[g][i] * groups_dp[g][n] % mod);
            }
        }
        return ans;
    }

private:
    const int mod = 1'000'000'007;

    void add(int &x, int y) {
        x += y;
        if (x >= mod) {
            x %= mod;
        }
    }
};
