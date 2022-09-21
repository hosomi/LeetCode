class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {

        vector<int> result;
        result.reserve(std::size(queries));
        auto accumulate = std::accumulate(std::begin(nums), std::end(nums),
            0, [](auto s, auto i) {
                return s + (i % 2 ? 0 : i); 
            }
        );

        for (const auto & q : queries) {
            accumulate -= nums[q[1]]%2 ? 0 : nums[q[1]];
            nums[q[1]] += q[0];
            accumulate += nums[q[1]]%2 ? 0 : nums[q[1]];
            result.push_back(accumulate);
        }
        return result;
    }
};
