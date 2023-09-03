/**
 * @param {number} m
 * @param {number} n
 * @return {number}
 */
var uniquePaths = function(m, n) {
    const fill = new Array(m).fill().map(() => new Array(n).fill(1));
    for (let i = m - 2; i >= 0; i--) {
        for (let j = n - 2; j >= 0; j--) {
            fill[i][j] = fill[i+1][j] + fill[i][j + 1];
        }
    }
    return fill[0][0];
};
