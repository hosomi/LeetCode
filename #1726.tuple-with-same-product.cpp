class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {

        unordered_map<int,int> m;
        for (int i{}; i < size(nums); ++i) {
            for (int j{i + 1}; j < size(nums); ++j) {
                ++m[nums[i]*nums[j]];
            }
        }

        int out{};
        for (const auto & [i, j] : m) {
            out += 4 * j * (j - 1);
        }
        return out;
    }
};
