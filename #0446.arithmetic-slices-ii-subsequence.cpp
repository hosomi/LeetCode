class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {

        int size = nums.size();
        vector<unordered_map<long, long>> dp(size);
        int result = 0;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < i; j++) {
                long diff = (long)nums[i] - (long)nums[j];
                dp[i][diff]++;
                if (dp[j].find(diff) != dp[j].end()) {
                    dp[i][diff] += dp[j][diff];
                    result += dp[j][diff];
                }
            }
        }
        return result;
    }
};
