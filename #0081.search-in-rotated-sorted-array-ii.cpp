class Solution {
public:
    bool search(vector<int>& nums, int target) {

        int size = nums.size();
        if (size == 0) {
            return false;
        }

        int left = 0;
        int right = size - 1;
        int middle;
        while(left <= right) {
            middle = (left + right) / 2;
            if (nums[middle] == target) {
                return true;
            }

            if(nums[middle] > nums[left]) {
                if (target >= nums[left] && target < nums[middle]) {
                    right = middle - 1;
                } else {
                    left = middle + 1;
                }
            } else if (nums[middle] < nums[left]) {
                if(target > nums[middle] && target <= nums[right]) {
                    left = middle + 1;
                } else {
                    right = middle - 1;
                }
            } else {
                left++;
            }
        }
        return false;
    }
};
