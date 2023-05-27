class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        
        int size= stoneValue.size();
        vector<int> dp(4, INT_MIN);
        for (int i = size - 1; i >= 0; i--) {
            dp[i%4] = INT_MIN;
            for (int j = 0, take = 0; j <= 2 && i + j < size; j++) {
                take += stoneValue[i + j];
                dp[i % 4] = std::max(dp[i % 4],
                    take - ((i + j + 1 < size) ? dp[(i + j + 1) % 4] : 0));
            }
        }
        
        if (dp[0] > 0) {
            return "Alice";
        }
        if (dp[0] < 0) {
            return "Bob";
        }
        return "Tie";
    }
};
