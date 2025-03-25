class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        
        vector<vector<int>> horizontal;
        vector<vector<int>> vertical;
        for (auto& rect : rectangles) {
            horizontal.push_back({rect[1], rect[3]});
            vertical.push_back({rect[0], rect[2]});
        }
        return  merge(horizontal) >= 2 || merge(vertical) >= 2;
    }

private:
    int merge(vector<vector<int>>& intervals) {

        std::sort(intervals.begin(), intervals.end());
        int start = intervals[0][0];
        int end = intervals[0][1];
        int count = 0;
        for (int i = 1; i < intervals.size(); i++) {
            if (end <= intervals[i][0]) {
                count++;
            }
            end = std::max(end, intervals[i][1]);
        }
        return count;
    }
};
