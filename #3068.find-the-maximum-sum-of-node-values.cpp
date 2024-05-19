class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {

        long long sum = 0;
        long long cnt = 0;
        for (auto &i : nums) {
            if ((i ^ k) > i) {
                cnt++;
                i ^= k;
            }
            sum += i;
        }

        if (cnt & 1) {
            int min = 1e9;
            for (auto i : nums) {
                min = std::min(min, i - (i ^ k));
            }
            sum -= min;
        }
        return sum;
    }
};
