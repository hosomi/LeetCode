class Solution {
public:
    int findMin(vector<int>& nums) {

        int l = 0;
        int r = nums.size() -1;
        int result = nums[0];
        int middle;
        while (l <= r) {
            middle = (l + r) / 2;
            if (nums[l] <= nums[middle]) {
                if (result >= nums[l]) {
                    result = nums[l];
                }
                l = middle + 1;
            } else {
                if (result >= nums[middle]) {
                    result = nums[middle];
                }
                r = middle - 1;
            }
        }
        return result;
    }
};
