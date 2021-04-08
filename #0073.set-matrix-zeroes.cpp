class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int rowSize = matrix.size();
        int colSize = matrix[0].size();
        vector<int> rows(rowSize);
        vector<int> cols(colSize);
        for (int i = 0; i < rowSize; ++i) {
            for (int j = 0; j < colSize; ++j) {
                rows[i] |= (matrix[i][j] == 0);
                cols[j] |= (matrix[i][j] == 0);
            }
        }

        for (int i = 0; i < rowSize; ++i) {
            for (int j = 0; j < colSize; ++j) {
                if (rows[i] || cols[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
