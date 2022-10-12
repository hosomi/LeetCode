class Solution {
public:
    int largestPerimeter(vector<int>& nums) {

        int size = nums.size();
        std::sort(begin(nums), end(nums));
        for (int i = size - 3; i >= 0; i--) {
            if (nums[i] + nums[i + 1] > nums[i + 2]) {
                return (nums[i]+nums[i + 1]+nums[i + 2]);
            }
        }
        return 0;
    }
};
