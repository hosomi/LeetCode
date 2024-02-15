class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        std::sort(begin(nums), end(nums));
        long long sum = nums[0] + nums[1]; 
        long long result = 0;
        for (int i = 2; i < nums.size(); i++) {
            if (sum > nums[i]) {
                 result = sum + nums[i];
            }
            sum += nums[i];
        }
        return result == 0 ? - 1 : result;
    }
};
