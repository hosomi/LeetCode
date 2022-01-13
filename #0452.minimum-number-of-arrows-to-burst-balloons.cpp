class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {

        if (points.size() == 0) {
            return 0;
        }

        std::sort(points.begin(), points.end(), 
            [](vector<int>& a, vector<int>& b) {
                return a[1] < b[1];
        });

        int index = points[0][1];
        int result = 1;
        for (vector<int>& point : points) {
            if (point[0] <= index) {
                continue;
            }
            result++;
            index = point[1];
        }
        return result;
    }
};
