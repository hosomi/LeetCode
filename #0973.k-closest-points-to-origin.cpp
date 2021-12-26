class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        std::sort(points.begin(), points.end(), [&](
            const vector<int>& x, const vector<int>& y) {
            return x[0] * x[0] + x[1] * x[1] < y[0] * y[0] + y[1] * y[1];
        });
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};
