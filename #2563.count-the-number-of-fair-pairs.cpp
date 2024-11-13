class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {

        long long result = 0;
        auto begin = nums.begin();
        auto end = nums.end();
        std::sort(begin, end);
        for (int i = 0; i < nums.size() - 1; ++i) {
            result += upper_bound(begin + i + 1, end, upper - nums[i])
                - lower_bound(begin + i + 1, end, lower - nums[i]);
        }
        return result;
    }
};
