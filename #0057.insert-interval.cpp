class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        int size = intervals.size();
        int index = 0;
        vector<vector<int>> result;
        while (index < size && intervals[index][1] < newInterval[0]) {
            result.push_back(intervals[index]);
            ++index;
        }

        int start = newInterval[0];
        int end = newInterval[1];
        while (index < size && intervals[index][0] <= end) {
            start = min(intervals[index][0], start);
            end = max(intervals[index][1], end);
            ++index;
        }

        result.push_back({start, end});
        
        while (index < size) {
            result.push_back(intervals[index]);
            ++index;
        }

        return result;
    }
};
