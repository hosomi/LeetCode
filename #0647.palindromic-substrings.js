/**
 * @param {string} s
 * @return {number}
 */
var countSubstrings = function(s) {
    let result = 0;
    for (let i = 0; i < s.length; i++) {
        for (let j = i, k = i; s[j] && s[j]==s[k]; j--,k++) {
            result++;
        }
        for (let j = i, k = i + 1; s[j] && s[j] == s[k]; j--, k++) {
            result++;
        }
    }
    return result;
};
