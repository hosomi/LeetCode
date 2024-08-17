class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {

        vector<long long> results((int)points[0].size(), 0);
        for (auto i = 0; i < points.size(); i++) {
            for (auto j = 0; j < points[i].size(); j++) {
                results[j] += points[i][j];
                if (j > 0) {
                    results[j] = std::max(results[j], results[j - 1] - 1);
                }
            }

            for (int j = points[i].size() - 2; j >= 0; j--) {
                results[j] = std::max(results[j], results[j + 1] - 1);
            }
        }
        return *max_element(results.begin(), results.end());
    }
};
