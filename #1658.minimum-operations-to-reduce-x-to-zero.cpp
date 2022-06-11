class Solution {
public:
    int minOperations(vector<int>& nums, int x) {

        int size = nums.size();
        int sum = std::accumulate(begin(nums), end(nums), 0);
        int left = 0;
        int right = 0;
        int result = INT_MAX;
        while (left <= right) {
            if (sum >= x) {
                if (sum == x) {
                    result = std::min(result, left + size - right);
                }

                if (right < size) {
                    sum -= nums[right++];
                } else {
                    break;
                }
            } else {
                sum += nums[left++];
            }
        }
        return result == INT_MAX ? -1 : result;
    }
};
