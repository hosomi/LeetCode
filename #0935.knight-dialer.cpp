class Solution {
public:
    int knightDialer(int n) {

        int dp[n][10];
        for (int i = 0; i < 10; i++) {
            dp[0][i] = 1;
        }

        unordered_map<int, vector<int>> m;
        m.insert({1, {6, 8}});
        m.insert({2, {7, 9}});
        m.insert({3, {4, 8}});
        m.insert({4, {9, 3, 0}});
        m.insert({6, {7, 1, 0}});
        m.insert({7, {6, 2}});
        m.insert({8, {3, 1}});
        m.insert({9, {2, 4}});
        m.insert({0, {4, 6}});
        int mod = (int) 1e9 + 7;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 10; j++) {
                auto vec = m[j];
                dp[i][j] = 0; 
                for (int &v : vec) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][v]) % mod;
                }
            }
        }

        int result = 0;
        for (int i = 0; i < 10; i++) {
            result = (result + dp[n - 1][i]) % mod;
        }
        return result;
    }
};
