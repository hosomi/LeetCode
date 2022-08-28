class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {

        int row = mat.size();
        int col = mat[0].size();
        int diagonally = row  + col - 1;
        for (int k = 0; k < diagonally; k++) {
            vector<int> v;
            for (int i = max(row - 1 - k, 0),
                j = max(k - row + 1, 0);
                i < row && j < col; i++, j++) {
                v.push_back(mat[i][j]);
            }

            std::sort(v.begin(), v.end());
            for (int i = std::max(row - 1 - k, 0),
                 j = std::max(k - row + 1, 0),
                 t = 0; i < row && j < col; i++, j++, t++) {
                mat[i][j] = v[t];
            }
        }
        return mat;
    }
};
