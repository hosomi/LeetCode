class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int row_size = mat.size();
        if (row_size == 0) {
            return vector<vector<int>>();
        }
        int col_size = mat[0].size();
        vector<vector<int>> result(row_size,vector<int>(col_size));
        for (int i = 0; i < row_size; i++) {
            for (int j = 0; j < col_size; j++) { 
                if (mat[i][j] == 0) {
                    result[i][j] = 0;
               } else {
                   int left = INT_MAX - 1;
                   int top = INT_MAX - 1;
                   if (i - 1 >= 0) {
                       top = result[i - 1][j];
                   }
                   if (j - 1 >= 0) {
                       left = result[i][j - 1];
                   }
                   result[i][j] = min(INT_MAX - 1, min(left,top) + 1);
               }
            }
        }

        for (int i = row_size - 1;i >= 0; i--) {
            for (int j = col_size - 1; j >= 0; j--) {
                if (result[i][j] != 0 && result[i][j] != 1) {
                    int down = INT_MAX - 1;
                    int right = INT_MAX - 1;
                    if (i + 1 < row_size) {
                        down = result[i + 1][j];
                    }
                    if (j + 1 < col_size) {
                        right = result[i][j + 1];
                    }
                    result[i][j] = std::min(result[i][j], std::min(down,right) + 1);
                }
            }
        }
        return result;
    }
};
