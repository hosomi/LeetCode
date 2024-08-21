/**
 * @param {string} s
 * @return {number}
 */
var strangePrinter = function(s) {
    const n = s.length;
    const dp = new Array(n).fill(0)
        .map(() => new Array(n).fill(0));

    for (let i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    for (let i = 2; i <= n; i++) {
        for (let j = 0; j <= n - i; j++) {
            const k = j + i - 1;
            dp[j][k] = i;
            for (let l = j; l < k; l++) {
                dp[j][k] = Math.min(dp[j][k],
                    dp[j][l] + dp[l + 1][k]);
            }

            if (s[j] === s[k]) {
                dp[j][k]--;
            }
        }
    }
    return dp[0][n - 1];
};
