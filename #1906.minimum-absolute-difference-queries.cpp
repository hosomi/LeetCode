class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {

        int size = nums.size();
        vector<int> result;
        vector<int> idx[101];
        for (int i = 0; i < size; ++i) {
            idx[nums[i]].push_back(i);
        }

        size = queries.size();
        for (int i = 0; i < size; ++i) {
            int pre = 0;
            int min = INT_MAX;
            for (int j = 1; j <= 100; ++j) {
                auto it = std::lower_bound(begin(idx[j]), end(idx[j]), queries[i][0]);
                if (it != std::end(idx[j]) && *it <= queries[i][1]) {
                    min = std::min(min, pre == 0 ? INT_MAX : j - pre);
                    pre = j;
                }
            }
            result.push_back(min == INT_MAX ? -1 : min);
        }
        return result;
    }
};
