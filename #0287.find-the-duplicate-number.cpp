class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int result = 0;
        for (auto n : nums) {
            if (nums[abs(n) - 1] < 0) {
                result = std::abs(n);
                break;
            }
            nums[std::abs(n) - 1] =- nums[std::abs(n) - 1];
        }
        return result;
    }
};
