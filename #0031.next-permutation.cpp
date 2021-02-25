class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int size = nums.size() - 2;
        int index;
        while (size >= 0 && nums[size + 1] <= nums[size]) {
            --size;
        }

        if (size >= 0) {
            index = nums.size() - 1;
            while (index >= 0 && nums[index] <= nums[size]) {
                --index;
            }
            swap(nums[size], nums[index]);
        }

        return reverse(begin(nums) + size + 1, end(nums));
    }
};
