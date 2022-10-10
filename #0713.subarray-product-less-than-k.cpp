class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        int size = nums.size();
        int left = 0;
        int right = 0;
        long long num = 1LL;
        int result = 0;
        for (int right = 0; right < size; ++right) {
            num *= nums[right];
            while (left < size && num >= k) {
                num /= nums[left];
                ++left;
            }

            if (left <= right) {
                result += (right - left + 1);
            }
        }
        return result;
    }
};
