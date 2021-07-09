class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {

        int row = dungeon.size();
        int col = dungeon[0].size();
        vector<vector<int>> result(row + 1, vector<int>(col + 1, INT_MAX));
        result[row][col - 1] = result[row - 1][col] = 1;  
        for (int i = row - 1; i >= 0; --i) {
            for (int j = col - 1; j >= 0; --j) {
                result[i][j] =
                    std::max(std::min(result[i+1][j], result[i][j+1]) - dungeon[i][j], 1);
            }
        }
        return result[0][0];
    }
};
