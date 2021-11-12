class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {

        row = matrix.size();
        if (row == 0) {
            return 0;
        }

        col = matrix[0].size();
        flag.resize(row);
        int result = 1;
        for (int i = 0; i < row; ++i) {
            flag[i].resize(col, -1);
        }

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                int temp = dfs(matrix, i, j);
                result = result < temp ? temp : result;
            }
        }
        return result;
    }

private:
    int row;
    int col; 
    vector<vector<int>> flag;

    int dfs(vector<vector<int>>& matrix, int x, int y) {

        if (flag[x][y] != -1) {
             return flag[x][y];
        }

        int result = 1;
        if (x>0 && matrix[x-1][y] > matrix[x][y]) {
            result = max(result, 1 + dfs(matrix, x-1, y));
        }
        if (x<row-1 && matrix[x+1][y] > matrix[x][y]) {
            result = max(result, 1 + dfs(matrix, x+1, y));
        }
        if (y>0 && matrix[x][y-1] > matrix[x][y]) {
            result = max(result, 1 + dfs(matrix, x, y-1));
        }
        if (y<col-1 && matrix[x][y+1] > matrix[x][y]) {
            result = max(result, 1 + dfs(matrix, x, y+1));
        }
            
        flag[x][y] = result;
        return result;
    }
};
