class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {

        int size = nums.size();
        int dp[size][3];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 0;
        dp[0][1] = dp[0][2]= -10001;
        dp[0][nums[0]%3] = nums[0];
        for (int i=1; i < size; i++) {
            int mod = nums[i] % 3;
            for (int j = 0; j < 3; j++) {
                dp[i][(j + mod) % 3] =
                    std::max(dp[i - 1][(j + mod) % 3], 
                             dp[i - 1][j] + nums[i]);
            }
        }
        return dp[size-1][0]; 
    }
};
