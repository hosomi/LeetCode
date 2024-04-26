class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {

        vector<vector<int>> dp(grid.size(), vector<int> (grid[0].size(), -1));
        for (int i = 0; i < grid.size();i++) {
            dp[0][i]=grid[0][i];
        }
        
        int result = INT_MAX;
        for (int i = 1; i < grid.size(); i++) {
            for (int j = 0; j < grid.size(); j++) {
                int min = INT_MAX;
                for (int k = 0; k < grid.size(); k++) {
                    if (j == k) {
                        continue;
                    }

                    min = std::min(min, grid[i][j]+dp[i-1][k]);
                }
                dp[i][j] = min;
            }
        }

        for (int i = 0; i < grid[0].size(); i++) {
            result = std::min(result, dp[grid.size() - 1][i]);
        }
        return result;
    }
};
