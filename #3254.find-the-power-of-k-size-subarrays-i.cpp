class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {

        int n = nums.size();
        vector<int> dp( n + 1, 0);
        for (int i = 2; i <= n; i++) {
            if (nums[i - 1] == nums[i - 2] + 1) {
                dp[i] = dp[i - 1] + 1;
            }
        }

        vector<int> results(n - k + 1, -1);
        for (int i = 1; i <= n - k + 1; i++) {
            if (dp[i + k - 1] == dp[i] + k - 1) {
                results[i - 1] = nums[i + k - 2];
            }
        }
        return results;
    }
};
