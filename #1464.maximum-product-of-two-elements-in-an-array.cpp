class Solution {
public:
    int maxProduct(vector<int>& nums) {

        std::sort(nums.begin(), nums.end());
        int index = nums.size() - 1;
        return (nums[index - 1] - 1) * (nums[index] - 1);
    }
};
