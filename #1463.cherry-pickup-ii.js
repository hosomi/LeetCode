/**
 * @param {number[][]} grid
 * @return {number}
 */
var cherryPickup = function(grid) {
    const memo = {};

    const isOffGrid = (i, j) =>
        j < 0
        || j >= grid[0].length
        || i >= grid.length;

    const move = (i, j, k) => {
        const memoKey = `${i}-${j}-${k}`;
        if (memo.hasOwnProperty(memoKey)) {
            return memo[memoKey];
        }

        if (isOffGrid(i, j) || isOffGrid(i, k)) {
            memo[memoKey] = 0;
            return 0;
        }

        const val = j === k ? grid[i][j] : grid[i][j] + grid[i][k];
        const maxVal = val + Math.max(
            move(i + 1, j - 1, k - 1),
            move(i + 1, j, k),
            move(i + 1, j + 1, k + 1),
            move(i + 1, j - 1, k),
            move(i + 1, j - 1, k + 1),
            move(i + 1, j, k - 1),
            move(i + 1, j, k + 1),
            move(i + 1, j + 1, k - 1),
            move(i + 1, j + 1, k),
        );

        memo[memoKey] = maxVal
        return maxVal;

    }

    return move(0, 0, grid[0].length - 1);
};
