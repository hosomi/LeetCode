/**
 * @param {string[]} words
 * @return {number}
 */
var longestStrChain = function(words) {
    words.sort((left, right) => left.length - right.length);
    let dp = {};
    let max = 0;
    for (let word of words) {
        let len = 0;
        for (let i = 0; i < word.length; ++i) {
            let predecessor = word.slice(0, i) + word.slice(i + 1);
            len = Math.max(len, (dp[predecessor] || 0) + 1);
        }
        dp[word] = Math.max(max, len);
    }
    return Math.max(...Object.values(dp));
};
