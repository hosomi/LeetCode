class Solution {
public:
    bool validPartition(vector<int>& nums) {

        int n = nums.size();
        if (n < 2) {
            return 0;
        }

        if (n == 2) {
            return nums[0] == nums[1];
        }

        if (n == 3) {
            if (nums[0] == nums[1] && nums[1] == nums[2]) {
                return 1;
            }

            if ((nums[0] + 1) == nums[1] && (1 + nums[1]) == nums[2]) {
                return 1;
            }
            return 0;
        }

        vector<int> dp(n + 3, 0);
        dp[n - 1] = 0;
        dp[n - 2] = (nums[n - 1] == nums[n - 2]);
        dp[n - 3] = (
            (nums[n - 1] == nums[n - 2] && nums[n - 2] == nums[n - 3])
            || (
                (1 + nums[n - 3]) == nums[n - 2]
                && (1 + nums[n - 2]) == nums[n - 1]
            )
        );

        for (int i = n - 4; i >= 0; i--) {
            int result = (nums[i] == nums[i + 1] && dp[i + 2]);
            result = result || (
                nums[i] == nums[i + 1]
                && nums[i + 1] == nums[i + 2]
                && dp[i + 3]
            );
            result = result || (
                (1 + nums[i]) == nums[i +1 ]
                && (1 + nums[i + 1]) == nums[i + 2]
                && dp[i + 3]
            );
            dp[i] = result;
        }
        return dp[0];
    }
};
