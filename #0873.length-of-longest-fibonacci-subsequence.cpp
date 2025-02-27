class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {

        int n = arr.size();
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++) {
            m[arr[i]] = i;
        }

        vector<vector<int>> dp(n, vector<int>(n, 0));
        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int key = arr[j]-arr[i];
                int idx = (m.find(key) != m.end()) ? m[key] : -1;
                if (idx > -1 && idx < i) {
                    dp[i][j] = std::max(dp[i][j], 1 + dp[idx][i]);
                    ans = std::max(ans, dp[i][j]);
                }
            }
        }
        return (ans == 0)? 0 : ans + 2;
    }
};
