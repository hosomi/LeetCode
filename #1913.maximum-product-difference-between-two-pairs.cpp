class Solution {
public:
    int maxProductDifference(vector<int>& nums) {

        std::sort(nums.begin(), nums.end());
        int size = nums.size();
        int right = nums[0]*nums[1];
        int left = nums[size - 1] *nums[size - 2];
        return left - right;
    }
};
