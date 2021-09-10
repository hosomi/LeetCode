class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int size = nums.size();
        vector<int> result(size, 1);
        for (int i = 1; i < size; ++i) {
            result[i] = result[i - 1] * nums[i - 1];
        }

        int accumulate = 1;
        for (int i = size - 1; i >= 0; --i) {
            result[i] *= accumulate;
            accumulate *= nums[i];
        }
        return result;
    }
};
