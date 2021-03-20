class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        vector<int> v(nums.size());
        v[0] = nums[0];
        int size = nums.size();
        for (int i = 1; i < size; ++i) {
            v[i] = max(v[i - 1] + nums[i], nums[i]);
        }

        return *std::max_element(v.begin(), v.end());
    }
};
