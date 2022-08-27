class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {

        int rowSize = std::size(matrix);
        int colSize = std::size(matrix[0]);
        vector<vector<int>> sum(rowSize, vector<int>(colSize + 1));
        int result = INT_MIN;
        for (int j = 0; j < colSize; ++j) {
            for (int i = 0; i < rowSize; ++i) {
                sum[i][j+1] = matrix[i][j] + sum[i][j];
            }

            for (int l = 0; l <= j; ++l) {
                int prefix = 0;
                set<int> s;
                for (int i = 0; i < rowSize; ++i) {
                    s.insert(prefix);
                    prefix += sum[i][j+1] - sum[i][l];
                    auto it = s.lower_bound(prefix - k);
                    if (it != s.end()) {
                        result = std::max(result, prefix - *it);
                    }
                }
            }
        }
        return result;
    }
};
