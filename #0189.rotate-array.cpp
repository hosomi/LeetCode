class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        if (nums.empty()) {
            return;
        }

        k %= nums.size();
        if (k == 0) {
            return;
        }

        std::reverse(begin(nums), std::end(nums));
        std::reverse(begin(nums), std::begin(nums) + k);
        std::reverse(begin(nums) + k, std::end(nums));
    }
};
