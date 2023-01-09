class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        std::sort(intervals.begin(), intervals.end(),
            [](vector<int>& left, vector<int>& right) {
                return left[1] < right[1];
            }
        );
        
        int discarded = 0;
        int last = INT_MIN;
        for (vector<int> interval : intervals) {
            if (last > interval[0]) {
                ++discarded;
            } else {
                last = interval[1];
            }
        }
        return discarded;
    }
};
