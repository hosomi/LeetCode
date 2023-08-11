class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        int size = coins.size();
        vector<vector<int>>dp(size + 1,
            vector<int>(amount+1,0));
        for (int i = 0; i <= size; i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= size; i++) {
            for (int j = 0; j <= amount; j++) {
                dp[i][j] = coins[i-1] <= j ?
                    dp[i][j - coins[i - 1]] + dp[i - 1][j] :
                    dp[i - 1][j];
            }
        }
        return dp[size][amount];
    }
};
