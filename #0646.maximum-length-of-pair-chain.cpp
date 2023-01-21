class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        
        int size = pairs.size();
        vector<int> dp(size, 1);
        std::sort(pairs.begin(), pairs.end());
        for (int i = 1; i < size; i++) {
            for (int j = 0; j < i; j++) {
                if (pairs[i][0] > pairs[j][1]
                    && dp[i] < dp[j] + 1) {
                    dp[i]=dp[j]+1;
                }
            }
        }

        int result = 0;
        for (int i = 0;i < size; i++) {
            if (result < dp[i]) {
                result = dp[i];
            }
        }
        return result;
    }
};
