class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {

        int duplication = -1;
        for (int n : nums) {
            if (nums[abs(n) - 1] < 0) {
                duplication = abs(n);
            } else {
                nums[abs(n) - 1] *= -1;
            }
        }

        int size = nums.size();
        int missing = -1;
        for (int i = 0; i < size; i++) {
            if (nums[i] > 0) {
                missing = i + 1;
            }
        }
        return vector<int> {duplication, missing};
    }
};
