class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
    
        auto result = 0;
        auto range = 0;
        while (range < n) {
            auto max = range;
            for(auto i = 0; i <= n; ++i) {
                if (!(range <= i + ranges[i] 
                    && range >= i - ranges[i])) {
                    continue;
                }
                max = std::max(max, i + ranges[i]);
            }

            if (max == range) {
                return -1;
            }
            ++result;
            range = max;
        }
        return result;
    }
};
