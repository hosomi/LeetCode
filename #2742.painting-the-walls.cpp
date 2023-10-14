class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {

        int size = time.size();
        vector<vector<int>> dp(size + 1,
            vector<int>(size + 1, 1000000000));
        dp[0][0] = 0;
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j <= size; ++j) {
                int min = std::min(size, j + time[i] + 1);
                dp[i+1][min] = std::min(dp[i + 1][min], dp[i][j] + cost[i]);
                dp[i+1][j] = std::min(dp[i + 1][j], dp[i][j]);
            }
        }
        return dp[size][size];
    }
};
