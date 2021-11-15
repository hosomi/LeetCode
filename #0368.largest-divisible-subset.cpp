class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {

        vector<int> result;
        if (nums.empty()) {
            return result;
        }

        std::sort(nums.begin(), nums.end());
        int size = nums.size();
        vector<int> dp(size, 1);
        vector<int> index(size, -1);
        int max_index = 0;
        int max_dp = 1;
        for (int i = 0; i < size; i++) {
            for (int j = i - 1; j >=0 ; j--) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    index[i] = j;
                }
            }
            if (max_dp < dp[i]) {
                max_dp = dp[i];
                max_index = i;
            }
        }
        for (int i = max_index; i != -1; i = index[i]) {
            result.push_back(nums[i]);
        }
        return result;
    }
};
