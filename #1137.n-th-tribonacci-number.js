/**
 * @param {number} n
 * @return {number}
 */
var tribonacci = function(n) {
    let arr = new Array(n + 1);
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 1;
    for (i = 3; i <= n; i++) {
        arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
    }
    return arr[n];
};
