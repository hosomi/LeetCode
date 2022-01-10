class Solution {
public:
    int minOperations(vector<int>& nums) {

        int size = nums.size();
        if (size <= 1) {
            return 0;
        }

        int result = 0;
        for (int i = 1; i < size; i++) {
            if (nums[i] <= nums[i-1]) {
                result += nums[i-1] + 1 - nums[i];
                nums[i] += nums[i-1] + 1 - nums[i];
            }
        }
        return result;
    }
};
