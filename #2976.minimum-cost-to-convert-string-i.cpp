class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {

        int n = 26;
        vector<vector<int>> dp(n, vector<int>(n, 1e7));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 0;
        }

        for (int i = 0; i < original.size(); ++i) {
            dp[original[i] - 'a'][changed[i] - 'a']
                = std::min(dp[original[i] - 'a'][changed[i] - 'a'], cost[i]);
        }

        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dp[i][j] > dp[i][k] + dp[k][j]) {
                        dp[i][j] = dp[i][k] + dp[k][j];
                    }
                }
            }
        }

        long long result = 0;
        for (int i = 0; i < source.size(); ++i) {
            if (dp[source[i] - 'a'][target[i] - 'a'] == 1e7) { 
                return -1;
            }
            result += dp[source[i] - 'a'][target[i] - 'a'];
        }
        return result;
    }
};
