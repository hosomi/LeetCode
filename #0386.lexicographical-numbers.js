/**
 * @param {number} n
 * @return {number[]}
 */
var lexicalOrder = function(n) {
    const arr = [];
    for (i = 1; i <= n; i++) {
        arr.push(i);
    }
    return arr.sort();
};
