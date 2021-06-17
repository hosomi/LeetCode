class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {

        int size = points.size();
        if (size == 1) {
            return 1;
        }

        map<pair<double, double>, unordered_set<int>> counter;
        double x;
        double y;
        int result = 0;
        for (int i = 0; i < size; ++i){
            for (int j = i + 1; j < size; ++j){
                if (points[i][0] == points[j][0]) {
                    x = INT_MAX;
                    y = points[i][0];
                } else {
                    x = (double)(points[i][1] - points[j][1])/(points[i][0] - points[j][0]);
                    y = points[i][1] + (-points[i][0]) * x;
                }

                counter[{x, y}].insert(i);
                counter[{x, y}].insert(j);
                result = std::max(result, (int)counter[{x, y}].size());
            }
        }
        return result;
    }
};
