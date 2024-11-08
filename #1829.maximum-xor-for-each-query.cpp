class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {

        int target = (1 << maximumBit) - 1;
        int sum = 0;
        for (int &i : nums) {
            sum ^= i;
            i = target ^ sum;
        }
        std::reverse(nums.begin(), nums.end());
        return nums;
    }
};
