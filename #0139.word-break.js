/**
 * @param {string} s
 * @param {string[]} wordDict
 * @return {boolean}
 */
var wordBreak = function(s, wordDict) {
    const dp = new Array(s.length + 1);
    dp[0] = true;

    for (let i = 0; i < s.length; i++) {
        if (!dp[i]) {
            continue;
        }

        wordDict.forEach(w => {
            if (s.slice(i, i + w.length) === w) {
                dp[i + w.length] = true;
            }
        });
    }
    return !!dp[s.length];
};
