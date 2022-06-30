class Solution {
public:
    int minMoves2(vector<int>& nums) {

        int halfsize = nums.size() >> 1;
        std::partial_sort(begin(nums), begin(nums) + halfsize + 1, end(nums));
        int mid = nums[halfsize];
        return std::accumulate(begin(nums), end(nums), 0, [mid](int left, int right) {
            return left + std::abs(mid - right);
        });
    }
};
