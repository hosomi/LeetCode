class Solution {
public:
    int countVowelStrings(int n) {

        if (n == 1) {
            return 5;
        }

        vector<vector<int>> dp(n + 1, vector<int>(5, 0));
        dp[1][0] = dp[1][1] = dp[1][2] = dp[1][3] = dp[1][4] = 1;
        int result = 0;
        for (int i = 2; i <=n ;i++) {
            for (int j = 0; j < 5; j++) {
                for (int k = 0; k <= j; k++) {
                    dp[i][j] += dp[i - 1][k];
                }
                if (i == n) {
                    result += dp[i][j];
                }
            }
           
        }
        return result;
    }
};
