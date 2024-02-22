/**
 * @param {number} n
 * @param {number[][]} trust
 * @return {number}
 */
var findJudge = function(n, trust) {
    let fill = Array(n + 1).fill(0);
    for (let [left, right] of trust) {
        fill[left] = fill[left] - 1;
        fill[right] = fill[right] + 1;
    }

    for (let i = 1; i < fill.length; i++) {
        if (fill[i] == n - 1) {
            return i;
        }
    }
    return -1;
};
