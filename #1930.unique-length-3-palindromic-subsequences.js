/**
 * @param {string} s
 * @return {number}
 */
var countPalindromicSubsequence = function(s) {
    let result = 0;
    for (let char of new Set(s)) {
        result += new Set(s.slice(s.indexOf(char) + 1,
            s.lastIndexOf(char))).size;
    }
    return result;
};
