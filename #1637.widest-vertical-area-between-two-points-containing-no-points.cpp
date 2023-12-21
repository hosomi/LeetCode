class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {

        std::sort(points.begin(), points.end());

        int size = points.size();
        int result = 0 ; 
        for (int i = 1; i < size; i++) {
            result = std::max(result, points[i][0] - points[i - 1][0]);
        }
        return result;
    }
};
