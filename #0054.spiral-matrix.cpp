class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int i = 0;
        int rowSize = matrix.size() - 1;
        int j = 0;
        int colSize = matrix[0].size() - 1;
        vector<int> result;
        while (i <= rowSize && j <= colSize) {
            for(int c = j; c <= colSize; ++c) {
                result.push_back(matrix[i][c]);
            }

            for(int r = i+1; r <= rowSize; ++r) {
                result.push_back(matrix[r][colSize]);
            }

            if (i < rowSize && j < colSize) {
                for(int c = colSize-1; c >= j; --c) {
                    result.push_back(matrix[rowSize][c]);
                }
                
                for(int r = rowSize-1; r >= i+1; --r) {
                    result.push_back(matrix[r][j]);
                }
            }

            ++i;
            ++j;
            --rowSize;
            --colSize;
        }
        return result;
    }
};
