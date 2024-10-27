class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size(); 
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int result = 0;
        for (int i = 1; i < m + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                if (matrix[i - 1][j - 1]) {
                    dp[i][j] = std::min({dp[i-1][j],
                        dp[i][j-1], dp[i-1][j-1]}) + 1;
                    result += dp[i][j];
                }
            }
        }
        return result;
    }
};
