class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {

        int size = nums.size();
        int min = nums[size - 1];
        long long int result = 0;
        for (int i = size - 2; i >= 0;i--) {
            if (nums[i] > min) {
                int ceil = std::ceil(nums[i] / double(min));
                result += ceil - 1;
                min = nums[i] / ceil;
            } else {
                min = nums[i];
            }
        }
        return result;
    }
};
