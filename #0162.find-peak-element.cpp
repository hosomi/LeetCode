class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        int i = 0;
        int size = nums.size() - 1;
        int index;
        while (i < size) {
            index = i + (size - i) / 2;
            if (nums[index] > nums[index + 1]) {
                size = index;
            } else {
                i = index + 1;
            }
        }
        return i;
    }
};
