class Solution {
public:
    bool canJump(vector<int>& nums) {

        int size = nums.size();
        int max = 0;
        for (int i = 0; i < size; ++i) {
            if (i > max || max >= size - 1) {
                break;
            }
            max = std::max(max, i + nums[i]);
        }
        return max >= size - 1;
    }
};
