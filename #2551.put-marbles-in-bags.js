/**
 * @param {number[]} weights
 * @param {number} k
 * @return {number}
 */
var putMarbles = function(weights, k) {
    if (k === 1) {
        return 0;
    }

    let arr = weights.slice(0, -1).map((v, i) => v + weights[i + 1]);
    arr.sort((a, b) => a - b);
    let min = arr.slice(0, k - 1).reduce((sum, v) => sum + v, 0);
    let max = arr.slice(-(k - 1)).reduce((sum, v) => sum + v, 0);
    return max - min;
};
