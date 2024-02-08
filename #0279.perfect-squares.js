/**
 * @param {number} n
 * @return {number}
 */
var numSquares = function(n) {
    const dp = Array(n + 1).fill(n);
    dp[0] = 0;
    for (let i = 0; i <= n; i++) {
        for (let j = 1; j <= n; j++) {
            let square = j * j;
            if (square + i > n) {
                break;
            }

            dp[i + square] = Math.min( 1 + dp[i], dp[i + square]);
        }
    }
    return dp[n];
};
