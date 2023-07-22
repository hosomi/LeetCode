/**
 * @param {number} n
 * @param {number} k
 * @param {number} row
 * @param {number} column
 * @return {number}
 */
var knightProbability = function(n, k, row, column) {
    let directions = [
        [-2, -1], [-1, -2], [1, -2],
        [2, -1], [2, 1], [1, 2], 
        [-1, 2], [-2, 1]];
    
    let dp = new Array(k + 1)
        .fill(0)
        .map(() => new Array(n).fill(0)
        .map(() => new Array(n).fill(0)))
    ;
    
    dp[0][row][column] = 1;
    for (let h = 1; h <= k; h++) {
        for (let i = 0; i < n; i++) {
            for (let j = 0; j < n; j++) {
                for (let [dx, dy] of directions) {
                    let newX = i + dx;
                    let newY = j + dy;
                    
                    if (newX >= 0 && newX < n && newY >=0 && newY < n) {
                        dp[h][i][j] += dp[h - 1][newX][newY] / 8;
                    }
                }
            }
        }
    }

    let result = 0;
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < n ; j++) {
            result += dp[k][i][j]
        }
    }
    return result;
};
