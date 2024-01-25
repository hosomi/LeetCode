/**
 * @param {string} text1
 * @param {string} text2
 * @return {number}
 */
var longestCommonSubsequence = function(text1, text2) {
    const length1 = text1.length;
    const length2 = text2.length;
    let dp = Array(length1 + 1)
        .fill(0).map(() => Array(length2 + 1)
        .fill(0));
    for (let i = length1 - 1; i >=0; i--) {
        for (let j = length2 - 1; j >= 0; j--) {
            text1[i] === text2[j] ?
                dp[i][j] = 1 + dp[i + 1][j + 1] :
                dp[i][j]= Math.max(dp[i][j + 1], dp[i + 1][j]);
        }
    }
    return dp[0][0];
};
