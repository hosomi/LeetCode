class Solution {
public:
    int minDifference(vector<int>& nums) {
 
            std::sort(nums.begin(), nums.end());
            int n = nums.size();
            return n <= 4 ? 0 :
                std::min(nums[n - 1] - nums[3],
                std::min(nums[n - 2] - nums[2],
                std::min(nums[n - 3] - nums[1],
                nums[n - 4] - nums[0])));
        }
};
