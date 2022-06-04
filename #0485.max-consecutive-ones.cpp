class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int max = 0;
        int cur = 0;
        for (int num : nums) {
            if (num) {
                cur++;
            } else {
                max = std::max(max, cur);
                cur = 0;
            }
        }
        return std::max(max, cur);
    }
};
