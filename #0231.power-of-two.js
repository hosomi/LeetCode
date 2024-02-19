/**
 * @param {number} n
 * @return {boolean}
 */
var isPowerOfTwo = function(n) {
    return n <= 0 ? false : (n & (n - 1)) === 0;
};
