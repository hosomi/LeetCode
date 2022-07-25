class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {

        int size = values.size();
        vector<vector<int>> result(size, vector<int>(size, 0));
        for (int i = size - 1; i >= 0; i--) {
            for (int j = i + 1; j < size; j++) {
                for (int k = i + 1; k <= j - 1; k++) {
                    result[i][j] = std::min(result[i][j] == 0 ? INT_MAX : result[i][j],
                        result[i][k] + values[i] * values[k] * values[j] + result[k][j]);
                }
            }
        }
        return result[0][size - 1];
    }
};
