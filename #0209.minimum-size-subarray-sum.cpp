class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int size = nums.size();
        int left = 0;
        int right = 0;
        int sum = 0;
        int result = size + 1;
        while (right < size) {
            while (sum < target && right < size) {
                sum += nums[right++];
            }
            while (sum >= target) {
                result = std::min(result, right - left);
                sum -= nums[left++];
            }
        }
        return result == size + 1 ? 0 : result;
    }
};
