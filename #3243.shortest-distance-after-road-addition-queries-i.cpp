class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {

        vector< vector<int>> m(n);
        for (int i = 0; i < n - 1; i++) {
            m[i].push_back(i + 1);
        }

        vector<int> dp(n);
        for (int i = 1; i < n; i++) {
            dp[i] = i;
        }

        vector<int> results;
        for (auto &q : queries) {
            m[q[0]].push_back(q[1]);
            for (int i = q[0]; i < n; i++) {
                for (auto& x : m[i]) {
                    dp[x] = min(dp[x], dp[i] + 1);
                }
            }
            results.push_back(dp[n - 1]);
        }

        return results;
    }
};
