class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {

        int n = robot.size();
        int m = factory.size();

        std::sort(robot.begin(), robot.end());
        std::sort(factory.begin(), factory.end());
        
        vector<long long> dp(n + 1, 1000000000000000);
        dp[0] = 0;
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < factory[j][1]; k++) {
                for (int i = n - 1; i >= 0; i--) {
                    dp[i+1] = std::min(dp[i + 1],
                        dp[i] + std::abs(factory[j][0] - robot[i]));
                }
            }
        }
        return dp[n];
    }
};
