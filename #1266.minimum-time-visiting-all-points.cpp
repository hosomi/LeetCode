class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        
        int size = points.size();
        int result = 0;
        for(int i = 0; i < size - 1; i++) {
            int x = std::abs(points[i + 1][0] - points[i][0]);
            int y = std::abs(points[i + 1][1] - points[i][1]);
            result += std::max(x,y);
        }
        return result;
    }
};
