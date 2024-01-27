/**
 * @param {number} n
 * @param {number} k
 * @return {number}
 */
var kInversePairs = function(n, k) {
    const mod = 1e9 + 7;
    let dp = Array(k + 1).fill(0);
    for (let i = 0; i <= n; ++i) {
        let temp = Array(k + 1).fill(0);
        temp[0] = 1;
        for (let j = 1; j <= k; ++j) {
            let val = (dp[j] + mod - ((j - i) >= 0 ? dp[j - i] : 0)) % mod;
            temp[j] = (temp[j - 1] + val) % mod;
        }
        dp = temp;
    }
    return ((dp[k] + mod - (k > 0 ? dp[k - 1] : 0)) % mod);
};
