class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int rowSize = heights.size();
        int colSize = heights[0].size();
        vector<vector<bool>>pacific(rowSize, vector<bool>(colSize, false));
        vector<vector<bool>>atlantic(rowSize, vector<bool>(colSize, false));
        vector<vector<int>> result;
        for (int i = 0; i < colSize; i++) {
            pacificAtlantic(heights,pacific, 0, i, -1);
            pacificAtlantic(heights,atlantic, rowSize - 1, i, -1);
        }
        
        for (int i = 0; i < rowSize; i++) {
            pacificAtlantic(heights,pacific, i, 0, -1);
            pacificAtlantic(heights,atlantic, i, colSize - 1, -1);
        }
        
        for (int i = 0; i < rowSize; i++) {
            for (int j=0;j < colSize; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }

private:
    void pacificAtlantic(vector<vector<int>>& mat,
             vector<vector<bool>>& ocean,
             int row, int col,int prev) {
        
        if (row < 0 || col < 0 || row >= mat.size() || col >= mat[0].size()
            || prev>mat[row][col] || ocean[row][col] == true) {
            return;
        }

        ocean[row][col] = true;
        pacificAtlantic(mat, ocean, row + 1, col, mat[row][col]);
        pacificAtlantic(mat, ocean, row - 1, col, mat[row][col]);
        pacificAtlantic(mat, ocean, row, col + 1, mat[row][col]);
        pacificAtlantic(mat, ocean, row, col - 1, mat[row][col]);
    }
};
