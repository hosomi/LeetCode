class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {

        unordered_map<int, int> m;
        int out{};
        std::sort(begin(nums), end(nums));
        for(const auto & num : nums) {
            int t = std::sqrt(num);
            if (t*t == num) {
                out = std::max(out, m[num]=m[t]+1);
            } else {
                m[num] = 1;
            }
        }
        return out > 1 ? out : -1;
    }
};
