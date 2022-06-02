class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {

        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> tmp;
        vector<vector<int>> result;
        for (int i = 0; i < col; i++) {
            tmp.clear();
            for (int j = 0; j < row; j++) {
                tmp.push_back(matrix[j][i]);
            }
            result.push_back(tmp);
        }
        return result;
    }
};
