class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {

        int l = -1;
        int r = -1;
        int result = 0;
        std::sort(intervals.begin(), intervals.end());
        for (vector<int>& v : intervals) {
            if (v[0] > l && v[1] > r) {
                l = v[0];
                result++;
            }
            r = std::max(r, v[1]);
        }
        return result;
    }
};
