class SummaryRanges {
public:
    SummaryRanges() {

    }

    void addNum(int val) {

        auto start = intervals.upper_bound(val);
        auto end = start == intervals.begin() ? intervals.end() : prev(start);
        if (end != intervals.end() && val <= end->second) {
            return;
        }

        bool left_merge = end != intervals.end() && val == end->second + 1;
        bool right_merge = start != intervals.end() && val == start->first - 1;
        if (left_merge == true && right_merge == true) {
            intervals[end->first] = start->second;
            intervals.erase(start->first);
        } else if (left_merge == true) {
            intervals[end->first] = val;
        } else if (right_merge == true) {
            intervals[val] = start->second;
            intervals.erase(start->first);
        } else {
            intervals[val] = val;
        }
        return;
    }
    
    vector<vector<int>> getIntervals() {

        vector<vector<int>> result;
        for (const auto [left, right] : intervals) {
            result.push_back({left, right});
        }
        return result;
    }

private:
    map<int, int> intervals;
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(val);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
