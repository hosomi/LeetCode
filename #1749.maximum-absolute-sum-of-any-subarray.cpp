class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {

        int n = nums.size();
        int sum = 0;
        int diff = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            diff -= nums[i];
            ans = std::max(ans, std::max(sum, diff));
            nums[i] =- nums[i];

            if (sum < 0) {
                sum = 0;
            }
            if (diff < 0) {
                diff = 0;
            }
        }
        return ans;
    }
};
