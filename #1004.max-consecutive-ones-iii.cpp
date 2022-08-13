class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int size = nums.size();
        int i = 0;
        int j = 0;
        for (; j < size; ++j) {
            if (nums[j] == 0) {
                --k;
            }

            if (k < 0 && nums[i++] == 0) {
                ++k;
            }
        }
        return j - i;
    }
};
