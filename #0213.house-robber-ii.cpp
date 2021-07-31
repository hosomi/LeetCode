class Solution {
public:
    int rob(vector<int>& nums) {

        int size = nums.size();
        if (size == 0) {
            return 0;
        }

        if (size == 1) {
            return nums[0];
        }

        vector<int> v1(size + 1, 0);
        vector<int> v2(size + 1, 0);
        v1[1] = nums[0];
        for (int i = 2; i <= size - 1; i++) {
            v1[i] = std::max(v1[i - 1], v1[i - 2] + nums[i - 1]);
        }

        v2[size - 1] = nums[size - 1];
        for (int i = size - 2; i; i--) {
            v2[i] = std::max(v2[i + 1], v2[i + 2] + nums[i]);
        }

        return std::max(v1[size -1], v2[1]);
    }
};
