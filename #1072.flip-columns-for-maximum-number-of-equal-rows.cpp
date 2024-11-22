class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        
        unordered_map<string, int> m;
        int r = matrix.size();
        int c = matrix[0].size();
        int result = 0;
        for (int i = 0; i < r; i++) {
            string pattern = "1";
            for (int j = 1; j < c; j++) {
                pattern += matrix[i][j] == matrix[i][0] ? '1' : '0';
            }
            m[pattern]++;
            result = std::max(result, m[pattern]);
        }
        return result;
    }
};
