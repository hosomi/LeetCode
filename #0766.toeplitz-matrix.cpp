class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {

        int row = matrix.size();
        int col = matrix[0].size();
        for (int i = 0; i < row - 1; i++) {
            int k = i;
            int j = 0;
            while (k < row - 1 && j < col - 1) {
                if (matrix[k][j] != matrix[k + 1][j + 1]) {
                    return false;
                }
                k++;
                j++;
            }            
        }

        for (int i = 0; i < col - 1;i++) {
            int k = i;
            int j = 0;
            while (k < col - 1 && j < row - 1) {
                if (matrix[j][k] != matrix[j + 1][k + 1]) {
                    return false;
                }
                j++;
                k++;
            }
        }
        return true;
    }
};
