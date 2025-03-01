class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {

        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        }

        int index = 0;
        vector<int> ans(n, 0);
        for (auto num : nums) {
            if (num != 0) {
                ans[index++] = num;
            }
        }
        return ans;
    }
};
