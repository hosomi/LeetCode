class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        int size = nums.size();
        if (size == 0) {
            return 0;
        }

        vector<int> v(size, 1);
        int result = 1;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    v[i] = std::max(v[i], v[j] + 1);
                }
            }
            result = std::max(result, v[i]);
        }
        return result;
    }
};
