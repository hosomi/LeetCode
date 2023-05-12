class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        
        int size = questions.size();
        vector<long long>dp(size + 1,0);
        for (int i = size - 1; i >= 0; i--) {
            int idx = questions[i][1]+i+1;
            dp[i] = idx < size ?
                questions[i][0] + dp[idx]
                : questions[i][0];
            dp[i] = std::max(dp[i], dp[i + 1]);
        }
        return dp[0];
    }
};
