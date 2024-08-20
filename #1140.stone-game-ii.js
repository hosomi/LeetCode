/**
 * @param {number[]} piles
 * @return {number}
 */
var stoneGameII = function(piles) {
    let n = piles.length;
    let sum = new Array(n).fill(0);
    for (let i = n - 1; i >= 0; i--) {
        sum[i] = i == n - 1 ? piles[i] : piles[i] + sum[i + 1]; 
    }

    let arr = new Array(n + 1)
        .fill(0)
        .map(el => new Array(n + 1).fill(0));
    for (let i = n - 1; i >= 0; i--) {
        for (let j = 1; j <= n; j++) {
            for (let x = 1; x <= 2 * j && i + x <= n; x++) {
                arr[i][j] = Math.max(arr[i][j],
                    sum[i] - arr[i + x][Math.max(j, x)]);
            }
        }
    }
    return arr[0][1]; 
};
