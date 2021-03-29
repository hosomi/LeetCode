class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int rowSize = obstacleGrid.size();
        int colSize = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1 || obstacleGrid[rowSize - 1][colSize - 1] == 1) {
            return 0;
        }

        vector<long long int> result(colSize + 1, 0LL);
        result[1] = 1;
        for (int i = 1; i <= rowSize; i++) {
            for (int j = 1; j <= colSize; j++) {
                if (i == 1 && j == 1) {
                    continue;
                }
                result[j] = (obstacleGrid[i - 1][j - 1] == 1) ? 0 : (result[j] + result[j - 1]);
            }
        }

        return result[colSize];
    }
};
