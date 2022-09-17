class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        
        return std::max(
            *std::max_element(nums.begin(), nums.end())
                - *std::min_element(nums.begin(), nums.end()) - 2 * k, 0);
    }
};
