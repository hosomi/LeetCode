class Solution {
public:
    int minOperations(vector<int>& nums) {

        std::sort(nums.begin(), nums.end());
        int size = nums.size();
        int max = 0;
        for (int i = 0, j = 0, count = 0; i < size && max < size - i; ) {
            for (; j < size && nums[j] - nums[i] <= size-1; ++j) {
                count += (j == i || nums[j] != nums[j-1]); 
            }

            max = std::max(max, count);
            if (++i < size) {
                count -= (i == j || nums[i] != nums[i-1]);
            }
        }
        return size - max;
    }
};
