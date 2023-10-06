/**
 * @param {number} n
 * @return {number}
 */
var integerBreak = function(n) {
    if (n <= 3) {
        return n - 1;
    }
  
    let exponent = Math.floor(n / 3);
    let remain = n % 3;
    if (remain === 0) {
        remain = 1;
    } else if (remain === 1) {
        exponent -= 1;
        remain = 4;
    }
    return (3 ** exponent) * remain;
};
