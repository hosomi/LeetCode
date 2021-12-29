class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {

        vector<unsigned int> result(target + 1, 0);
        result[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (int num : nums) {
                if (num <= i) {
                    result[i] += result[i - num];
                }
            }
        }
        return result[target];
    }
};
