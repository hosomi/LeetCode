class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {

        int rows = rowSum.size();
        int cols = colSum.size();
        vector<vector<int>> results(rows, vector<int> (cols, 0));
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++){
                results[i][j] = std::min(rowSum[i], colSum[j]);
                rowSum[i] -= results[i][j];
                colSum[j] -= results[i][j];
            }
        }
        return results;
    }
};
