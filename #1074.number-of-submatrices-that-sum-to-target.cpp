class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {

        int rowSize = matrix.size();
        int colSize = matrix[0].size();
        int result = 0;
        for (int i = 0; i < rowSize; i++) {
            for (int j = 1; j < colSize; j++) {
                matrix[i][j] += matrix[i][j - 1];
            }
        }
        
        for (int low = 0; low < colSize; low++) {
            for (int high = low; high < colSize; high++) {
                unordered_map<int, int> um;
                um[0] = 1;
                int cursor = 0;
                for (int row = 0; row < rowSize; row++) {
                    cursor += matrix[row][high] - ((low > 0) ?
                        matrix[row][low - 1] : 0);
                    result += um[cursor - target];
                    um[cursor]++;
                }
            }
        }
        return result;
    }
};
