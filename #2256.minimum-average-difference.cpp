class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {

        vector<long long> ps{0};
        for (int num : nums) {
            ps.push_back(num + ps.back());
        }

        long long size = nums.size();
        long long min = 0;
        long long sum = ps.back();
        long long d = INT_MAX;
        for (int i = 1; i < size; ++i) {
            int diff = std::abs(ps[i] / i - (sum - ps[i]) / (size - i));
            if (d > diff) {
                d = diff;
                min = i - 1;
            }
        }
        return d <= sum / size ? min : size - 1;
    }
};
