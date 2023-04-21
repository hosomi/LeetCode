class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        
        static const int min = 1000000007;
        int size = group.size();
        vector<vector<int>> dp(minProfit + 1, vector<int>(n + 1));
        dp[0][0] = 1;
        int result = 0;
        for (int k = 0; k < size; ++k) {
            int l = group[k];
            int p = profit[k];
            for (int i = minProfit; i >= 0; --i)
                for (int j = n - l; j >= 0; --j)
                    dp[std::min(i + p, minProfit)][j + l] = 
                        (dp[std::min(i + p, minProfit)][j + l] + dp[i][j]) % min;
        }

        
        for (const auto& p : dp[minProfit]) {
            result = (result + p) % min;
        }
        return result;
    }
};
