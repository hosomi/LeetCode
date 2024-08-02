class Solution {
public:
    int minSwaps(vector<int>& nums) {

        int n = nums.size();
        int total  = 0;
        for (int i = 0; i < n; i++) {
            total += nums[i];
        }

        int sum = 0;
        for (int i = 0; i < total; i++) {
            sum += nums[i];
        }

        int swaps = total - sum;
        for (int i = 1; i < n; i++) {
            sum += nums[(i + total - 1) % n];
            sum -= nums[i - 1];
            swaps = min(swaps, total - sum);
        }
        return swaps;
    }
};
