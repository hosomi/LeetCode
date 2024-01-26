/**
 * @param {number} m
 * @param {number} n
 * @param {number} maxMove
 * @param {number} startRow
 * @param {number} startColumn
 * @return {number}
 */
var findPaths = function(m, n, maxMove, startRow, startColumn) {
    let dp = {};
    return dfs(startRow, startColumn, maxMove);

    function dfs(startRow, startColumn, maxMove) {
        if (startRow < 0
            || startRow == m
            || startColumn < 0
            || startColumn == n) {
            return 1;
        }

        if (maxMove == 0) {
            return 0;
        }
        const key = `${startRow}#${startColumn}#${maxMove}`;
        if (dp[key] != undefined) {
            return dp[key];
        }
        
        let result = 0;
        result += dfs(startRow - 1, startColumn, maxMove-1);
        result += dfs(startRow + 1, startColumn, maxMove-1);
        result += dfs(startRow, startColumn-1, maxMove-1);
        result += dfs(startRow, startColumn+1, maxMove-1);
        result %= 1000000007;
        dp[key] = result;
        return result;
    };
};
