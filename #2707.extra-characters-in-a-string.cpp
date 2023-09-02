class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {

        int size = s.size();
        vector<int>dp(size + 1, 0);  
        for (int i = size - 1; i >= 0; i--) {
            dp[i] = dp[i + 1] + 1;
            for (auto it: dictionary) {
                if (s.compare(i, it.size(), it) ==0) {
                    dp[i] = std::min(dp[i], dp[i + it.length()]);
                }
            }
        }
        return dp[0];
    }
};
