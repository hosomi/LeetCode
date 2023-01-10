class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        
        int size = intervals.size();
        map<int, int> m;
        for (int i = 0; i < size; i++) {
            m[intervals[i][0]] = i;
        }
        
        vector<int> result(size);
        for (int i = 0; i < size; i++) {
            auto it = m.lower_bound(intervals[i][1]);
            result[i] = it == m.end() ? -1 : it->second;
        }
        return result;
    }
};
