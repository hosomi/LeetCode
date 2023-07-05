class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int size = nums.size();
        int i;
        int j;
        int k = 1;
        for (i = 0, j = 0; j < size; ++j) {
            if (nums[j] == 0) {
                --k;
            }

            if (k < 0 && nums[i++] == 0) {
                ++k;
            }
        }
        return j - i - 1;
    }
};
