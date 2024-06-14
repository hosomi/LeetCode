class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {

        int count = 0;
        std::sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i-1]) {
                continue;
            }

            int x = std::abs(nums[i] - nums[i - 1]) + 1;
            count += x;
            nums[i] += x;
        }
        return count;
    }
};
