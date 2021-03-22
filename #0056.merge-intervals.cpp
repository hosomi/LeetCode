class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end());
        for (vector<int>& interval : intervals) {
            if (result.empty() || result.back()[1] < interval[0]) {
                result.push_back(interval);
            } else {
                result[result.size()-1][1] = max(result.back()[1], interval[1]);
            }
        }
        return result;
    }
};
