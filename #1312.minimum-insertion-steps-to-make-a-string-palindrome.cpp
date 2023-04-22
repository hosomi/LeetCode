class Solution {
public:
    int minInsertions(string s) {
        
        string str = s;
        int size = s.size();
        reverse(s.begin(), s.end());
        vector<vector<int>> dp(size + 1,
            vector<int>(size + 1, 0));
        for (int i = 0; i <= size; ++i) {
            dp[i][0] = 0;
        }

        for (int j = 0; j <= size; ++j) {
            dp[0][j] = 0;
        }

        for (int i = 1; i <= size; ++i) {
            for (int j = 1; j <= size; ++j) {
                if (str[i - 1] == s[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return str.size() - dp[size][size];
    }
};
