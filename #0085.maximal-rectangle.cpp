class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {

        int rowSize = matrix.size();
        if (rowSize == 0) {
            return 0;
        }

        int colSize = matrix[0].size();
        vector<vector<int>> v(rowSize, vector<int>(colSize));
        for (int i = 0; i < rowSize; ++i) {
            for (int j = 0; j < colSize; ++j) {
                v[i][j] = (matrix[i][j] == '1') ? (j == 0 ? 1 : v[i][j - 1] + 1) : 0;
            }
        }

        int result = 0;
        int area;
        for (int i = 0; i < rowSize; ++i) {
            for (int j = 0; j < colSize; ++j) {
                area = INT_MAX;
                for (int k = i; k < rowSize; k++) {
                    area = std::min(area, v[k][j]);
                    if (area == 0) {
                        break;
                    }
                    result = std::max(area * (k - i + 1), result);
                }
            }
        }
        return result;
    }
};
