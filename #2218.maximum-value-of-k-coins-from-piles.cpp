class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        
        for (auto & v: piles) {
            int size = v.size();
            for (int i = 1; i < size; ++i) {
                v[i] += v[i-1];
            }
        }

        int row = piles.size();
        dp[0] = 0;
        for (int i = 1; i <= k; ++i) {
            dp[i] = INT_MIN;
        }

        for (int i = 0; i < row; ++i) {
            int col = piles[i].size();
            for (int j = k; j >= 0; --j) {
                for (int l = 1; l <= std::min(col, j); ++l) {
                    dp[j] = std::max(dp[j], dp[j-l] + piles[i][l-1]);
                }
            }
        }
        return dp[k];
    }

private:
    int dp[2001];
};
