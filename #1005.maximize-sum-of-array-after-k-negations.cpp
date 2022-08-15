class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {

        for (int i = 0; i < k; i++) {
            vector<int>::iterator it = std::min_element(nums.begin(), nums.end());
            *it = -*it;
        }
        return std::accumulate(nums.begin(), nums.end(), 0);
    }
};
