class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {

        unsigned int accumulate = std::accumulate(
            nums.begin(), nums.end(), 0, std::bit_xor<int>());
        accumulate &= -accumulate;
        vector<int> result(2, 0);
        for (auto &n : nums) {
            if (n & accumulate) {
                result[0] ^= n;
            } else {
                result[1] ^= n;
            }
        }
        return result;
    }
};
