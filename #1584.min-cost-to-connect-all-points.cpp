class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        int size = points.size();
        int i = 0;
        int connected = 0;
        vector<int> min(size, 10000000);
        int result = 0;
        while (++connected < size) {
            min[i] = INT_MAX;
            int min_j = i;
            for (int j = 0; j < size; ++j)
                if (min[j] != INT_MAX) {
                    min[j] = std::min(min[j], std::abs(
                        points[i][0] - points[j][0])
                        + std::abs(points[i][1] - points[j][1])
                    );
                    min_j = min[j] < min[min_j] ? j : min_j;
                }
            result += min[min_j];
            i = min_j;
        }
        return result;
    }
};
