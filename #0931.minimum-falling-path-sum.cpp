class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {

        int size = matrix.size();
        vector<vector<int>> v(size + 2, vector<int>(size + 2, INT_MAX));
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                v[i + 1][j + 1] = matrix[i][j];
            }
        }
        
        for(int i = size - 1; i >= 1; i--){
            for(int j = 1; j <= size; j++){
                v[i][j] += std::min({v[i + 1][j - 1], v[i + 1][j], v[i + 1][j + 1]});
            }
        }
        
        return *std::min_element(v[1].begin(), v[1].end());
    }
};
