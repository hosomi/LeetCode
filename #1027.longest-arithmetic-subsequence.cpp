class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {

        int size = nums.size();
        memset(dp , 0 , sizeof(dp));
        int maxlen = 1;
        for(int i = 1 ; i < size ;i++) {
            for (int j = 0; j < i; j++) {
                int diff = nums[i] - nums[j] + 500;
                dp[i][diff] = max(dp[i][diff] , 1 + dp[j][diff]);
                maxlen = std::max(maxlen , dp[i][diff]);
            }
        }
        return maxlen + 1;
    }

private:
    int dp[1001][1001];
};
