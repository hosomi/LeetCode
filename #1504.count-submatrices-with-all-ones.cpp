class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {

        int out{};
        for (int I{}; I < size(mat); ++I) {
            for (int J{}; J < size(mat[0]); ++J) {
                for (int j{J}, i{-1}, h{-1}; j >= 0 && mat[I][j]; --j, h = i) {
                    for (i = I; i > h && mat[i][j]; --i) {
                        out++;
                    }
                }
            }
        }
        return out;
    }
};
