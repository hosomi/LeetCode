/**
 * @param {number[][]} grid
 * @return {number}
 */
var numMagicSquaresInside = function(grid) {
    const m = grid.length;
    const n = grid[0].length;
    let count = 0;
    for (let i = 0; i < m - 2; i++) {
        for (let j = 0; j < n - 2; j++) {
            const sums = new Array(8).fill(0);
            const set = new Set();
            let isMagical = true;
            for (let k = 0; k < 3; k++) {
                for (let l = 0; l < 3; l++) {
                    const num = grid[i + k][j + l];
                    if (num === 0 || num > 9 || set.has(num)) {
                        isMagical = false;
                        break;
                    }

                    set.add(num);
                    sums[k] += num;
                    sums[3 + l] += num;

                    if (k === l) {
                        sums[6] += num;
                    }
                    if (k + l === 2) {
                        sums[7] += num;
                    }
                }
            } 
    
            if (!isMagical) {
                continue;
            }

            let areSame = true;
            for (let i = 1; i < 8; i++) {
                if (sums[i] != sums[i - 1]) {
                    areSame = false;
                    break;
                }
            }
            count += areSame;
        }
    }
    return count;
};
