class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        
        cuts.push_back(0);
        cuts.push_back(n);
        std::sort(cuts.begin(), cuts.end());
        
        int size = cuts.size();
        vector<vector<int>> dp(size, vector<int>(size));
        for (int i = size - 1; i >= 0; --i) {
            for (int j = i+2; j < size; ++j) {
                dp[i][j] = INT_MAX;
                for (int k = i + 1; k < j; ++k) {
                    dp[i][j] = std::min(dp[i][j],
                        cuts[j] - cuts[i] + dp[i][k] + dp[k][j]);
                }
            }
        }
        return dp[0][size - 1];
    }
};
