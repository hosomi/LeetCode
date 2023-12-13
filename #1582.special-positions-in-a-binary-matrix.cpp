class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        
        int row = mat.size();
        int col = mat[0].size();
        int result = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (mat[i][j] == 1
                    && numSpecial(mat, row, col, i, j)) {
                        result++;
                }
            }
        }
        return result;
    }

private:
    bool numSpecial(vector<vector<int>> mat,
        int row, int col, int i, int j) {

        for (int k = 0; k < col; k++) {
            if(mat[i][k] == 1 && k != j) {
                return false;
            }
        }

        for (int k = 0; k < row; k++) {
            if (mat[k][j] == 1 && k != i) {
                return false;
            }
        }

        return true;
    }
};
