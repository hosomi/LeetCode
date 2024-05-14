/**
 * @param {number[][]} grid
 * @return {number}
 */
var getMaximumGold = function(grid) {
    function getMaximumGold(left, right) {
        if (left < 0 || right < 0 
            || left >= n1 
            || right >= n2 
            || !grid[left][right]) {
            return 0;
        }

        const arr1 = [1, -1, 0, 0];
        const arr2 = [0, 0, 1, -1];
        const cell = grid[left][right];
        let max = 0;
        grid[left][right] = 0;
        for (let i = 0; i < arr1.length; i++) {
            max = Math.max(max,
                getMaximumGold(left + arr1[i], right + arr2[i]));
        }
        grid[left][right] = cell;
        return max + cell;
    }

    const n1 = grid.length;
    const n2 = grid[0].length;
    let maxPath = 0;
    for (let i = 0; i < n1; i++) {
        for (let j = 0; j < n2; j++) {
            if (grid[i][j]) {
                maxPath = Math.max(maxPath, getMaximumGold(i, j));
            }
        }
    }
    return maxPath;
};
