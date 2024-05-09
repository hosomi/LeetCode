class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        
        std::sort(rbegin(happiness), rend(happiness));

        long long max = 0;
        long long happi = 0;
        for (int i = 0; i < k; ++i) {
            max += std::max(0ll, happiness[i] - happi++);
        }
        return max;
    }
};
