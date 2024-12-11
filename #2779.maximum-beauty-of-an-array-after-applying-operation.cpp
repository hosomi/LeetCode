class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {

        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        int result = 0;
        for (int i = 0; i < n; i++) {
            int pos = upper_bound(nums.begin(),
                nums.end(), nums[i] + 2 * k) - nums.begin();
            result  = std::max(result, pos - i);
        }
        return result;
    }
};
