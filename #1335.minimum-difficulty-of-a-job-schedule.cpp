class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {

        int size = jobDifficulty.size();
        if (size < d) {
            return -1;
        }

        int dp[d][size];
        dp[0][0] = jobDifficulty[0];
        for (int i = 1; i < size; i++) {
            dp[0][i] = std::max(dp[0][i - 1],jobDifficulty[i]);
        }
        
        for (int i = 1; i < d;i++) {
            for (int j = i; j < size; j++) {
                int max = jobDifficulty[j];
                int min = INT_MAX;
                for (int k = j; k >= i; k--) {
                    max = std::max(max, jobDifficulty[k]);
                    min = std::min(min, dp[i - 1][k - 1] + max);
                }
                dp[i][j] = min;
            }
        }
        return dp[d - 1][size - 1];
    }
};
