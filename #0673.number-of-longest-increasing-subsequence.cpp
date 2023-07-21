class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        
        int size = nums.size();
        vector<int> dp(size, 1);
        vector<int> cnt(size + 1, 1);
        int max = 1;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]
                    && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    cnt[i] = cnt[j];
                } else if (nums[j] < nums[i]
                    && dp[j] + 1 == dp[i]) {
                    cnt[i] += cnt[j];
                }
            }
            max = std::max(max, dp[i]);
        }

        int result = 0;
        for (int i = 0; i < size; i++) {
            if (dp[i] == max) {
                result += cnt[i];
            }
        }
        return result;
    }
};
