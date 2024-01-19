/**
 * @param {number[][]} matrix
 * @return {number}
 */
var minFallingPathSum = function(matrix) {
    const length = matrix.length;
    const dp = JSON.parse(JSON.stringify(matrix));
    for (let i = 1; i < length; i++) {
        for (let j = 0; j < length; j++) {
            const a = dp[i - 1][j] ?? Infinity;
            const b = dp[i - 1][j + 1] ?? Infinity
            const c = dp[i - 1][j - 1] ?? Infinity;
            const v = dp[i][j];
            dp[i][j] = Math.min(v + a, v + b, v + c)
        }
    }
    return Math.min(...dp[length - 1]);
};
