class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        
        int size = nums.size();
        vector<pair<int, int>> v;
        for (int i = 0; i < size; i++) {
            v.push_back({nums[i], cost[i]});
        }
        std::sort(v.begin(), v.end());

        vector<long long> pref(size);
        long long prefCost = v[0].second;
        for (int i = 1; i < size; i++) {
            pref[i] = pref[i - 1] + prefCost * (v[i].first - v[i - 1].first);
            prefCost += v[i].second;
        }

        vector<long long> suff(size);
        long long suffCost = v[size - 1].second;
        for (int i = size - 2; i >= 0; i--) {
            suff[i] = suff[i + 1] + suffCost * abs(v[i].first - v[i + 1].first);
            suffCost += v[i].second;
        }

        long long result = 1e18;
        for (int i = 0; i < size; i++) {
            result = std::min(result, pref[i] + suff[i]);
        }
        return result;
    }
};
