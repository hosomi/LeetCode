class Solution {
public:
    int findMin(vector<int>& nums) {

        int i = 0;
        int n = nums.size() - 1 - 1;
        int middle;
        while (i <= n) {
            middle = (i + n) >> 1;
            if (nums[middle] < nums[n + 1]) {
                n = middle - 1;
            } else if(nums[middle] > nums[n + 1]) {
                i = middle + 1;
            } else {
                if (n - 1 >= 0 && nums[n - 1] > nums[n]) {
                    i = n;
                    break;
                }
                --n;
            }
        }
        return nums[i];
    }
};
