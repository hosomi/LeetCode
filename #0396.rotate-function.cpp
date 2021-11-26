class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {

        int size = nums.size();
        long subtotal = 0;
        long total = 0;
        for (int i = 0; i < size; i++) {
            subtotal += nums[i];
            total += (nums[i] * i);
        }

        long result = total;
        for (int i = 1; i < size; i++) {
            total = (total - subtotal + nums[i - 1] * (size));
            result = std::max(result, total);
        }
        return result;
    }
};
