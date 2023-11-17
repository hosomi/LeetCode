class Solution {
public:
    int minPairSum(vector<int>& nums) {
        
        std::sort(nums.begin(), nums.end());

        int size = nums.size();
        int max = -1;
        for (int i = 0; i < size / 2; i++) {
            max = std::max(max, nums[i] + nums[size - 1 - i]);
        }
        return max;
    }
};
