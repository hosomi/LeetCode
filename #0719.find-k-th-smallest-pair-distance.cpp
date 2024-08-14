class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {

        vector<int> v(1e6 + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                v[abs(nums[j] - nums[i])]++;
            }
        }

        for (int i = 1; i < v.size(); i++) {
            v[i] += v[i - 1];
        }
        return lower_bound(v.begin(), v.end(), k) - v.begin();
    }
};
