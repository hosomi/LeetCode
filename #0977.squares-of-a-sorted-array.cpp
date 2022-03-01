class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        int size = nums.size();
        for (int i = 0; i < size; i++) {
            nums[i] *= nums[i];
        }
        std::sort(nums.begin(), nums.end());
        return nums;
    }
};
