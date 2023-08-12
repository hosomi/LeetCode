/**
 * @param {number[][]} obstacleGrid
 * @return {number}
 */
var uniquePathsWithObstacles = function(obstacleGrid) {
    let row = obstacleGrid.length;
    let col = obstacleGrid[0].length;
    let dp = new Array(row + 1)
        .fill()
        .map(() => new Array(col + 1)
        .fill(0))
    ;

    for (let i = row - 1; i >= 0; i--) {
        for (let j = col - 1; j >= 0; j--) {
            dp[i][j] = i === row - 1 && j === col - 1 ? 
                obstacleGrid[i][j] === 0 ? 1 : 0 :
                obstacleGrid[i][j] === 1 ? 0 :dp[i + 1][j] + dp[i][j + 1]
            ;
        }
    }
    return dp[0][0];
};
