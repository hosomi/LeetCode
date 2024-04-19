/**
 * @param {character[][]} grid
 * @return {number}
 */
var numIslands = function(grid) {
    const x = [-1, 0, 0, 1];
    const y = [0, -1, 1, 0];
    const isCheck = (x, y) => {
        return x >= 0 && y >= 0 && x < grid.length
            && y < grid[0].length 
            && grid[x][y] === '1'
    };

    const isColor = (i, j) => {
        if (!grid[i][j]) {
            return;
        }

        grid[i][j] = '0';
        for (let k = 0 ; k < 4 ; k++ ) {
            const dx = x[k] + i;
            const dy = y[k] + j;
            if (isCheck(dx, dy) && grid[dx][dy] === '1') {  
                isColor(dx, dy);
            }
        }
    }

    let result = 0;
    for (let i = 0 ; i < grid.length ; i++) {
        for (let j = 0 ; j < grid[0].length ; j++) {
            if (grid[i][j] === '1') {  
                isColor(i, j);
                result++;
            }
        }
    }
    return result; 
};
