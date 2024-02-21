/**
 * @param {number} left
 * @param {number} right
 * @return {number}
 */
var rangeBitwiseAnd = function(left, right) {
    const p = Math.log2(left ^ right);
    return left >> p << p;   
};
