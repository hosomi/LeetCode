class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {

        int size = nums.size();
        int i = k;
        int j = k;
        int min = nums[k];
        int cur = nums[k];
        int result = nums[k];
        while (i > 0 || j < size - 1) {
            if (i == 0) {
                ++j;
            } else if (j == size - 1) {
                --i;
            } else if (nums[i-1] > nums[j+1]) {
                --i;
            } else {
                ++j;
            }
            cur = std::min(nums[i], nums[j]);
            min = std::min(min, cur);
            result = std::max(result, min * (j - i + 1));
            
        }
        return result;
    }
};
