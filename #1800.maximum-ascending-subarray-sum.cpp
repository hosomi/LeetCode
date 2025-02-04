class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {

        int max = nums[0];
        int curr = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i-1] < nums[i]) {
                curr += nums[i];
            } else {
                max = std::max(max, curr);
                curr = nums[i];
            }
        }
        return std::max(max, curr);
    }
};
