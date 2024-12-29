/**
 * @param {string[]} words
 * @param {string} target
 * @return {number}
 */
var numWays = function(words, target) {
    const mod = 1e9 + 7;
    const res = new Array(target.length + 1).fill(0);
    res[0] = 1;
    for (let i = 0; i < words[0].length; i++) {
        let count = new Array(26).fill(0);
        for (let word of words) {
            count[word.charCodeAt(i) - 97]++;
        }
        for (let j = target.length - 1; j >= 0; --j) {
            res[j + 1] += res[j] * count[target.charCodeAt(j) - 97] % mod;
        }
    }
    return res[target.length] % mod;
};
