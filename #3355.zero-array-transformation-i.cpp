class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {

        const size_t n = nums.size();
        std::vector<int> diff(n + 1);
        diff[0] = nums[0];
        for (int i = 1; i != n; ++i) {
            diff[i] = nums[i] - nums[i - 1];
        }

        for (const std::vector<int>& query : queries) {
            --diff[query[0]];
            ++diff[query[1] + 1];
        }

        int prev = diff[0];
        if (prev > 0) {
            return false;
        }
        
        for (size_t i = 1; i < n; ++i) {
            prev += diff[i];
            if (prev > 0) {
                return false;
            }
        }
        return true;
    }
};
