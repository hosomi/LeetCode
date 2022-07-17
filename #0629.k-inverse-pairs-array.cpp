class Solution {
public:
    int kInversePairs(int n, int k) {

        long long m = 1e9+7;
        vector<vector<int> > dp(n + 2,vector<int>(k + 2,0));   
        for (int i=1;i<=n;i++) {
            for (int j = 0; j <= k; j++) {
                if (j==0) {
                    dp[i][j] = 1;
                } else{
                    int sum = (
                        dp[i - 1][j] + m - ((j - i) >= 0 ? 
                                          dp[i - 1][j - i] : 0)
                    ) % m;  
                    dp[i][j] = (dp[i][j - 1] + sum) % m;
                }
            }
        }

        return (
            dp[n][k] + m - ((k - 1) >= 0 ? dp[n][k - 1] : 0)
        ) % m;
    }
};
