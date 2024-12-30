/**
 * @param {number} low
 * @param {number} high
 * @param {number} zero
 * @param {number} one
 * @return {number}
 */
var countGoodStrings = function(low, high, zero, one) {
    const MOD = 1e9 + 7;
    const DP = new Array(high + 1).fill(0);
    let ans = 0;
    DP[0] = 1;
    for (let i = 1; i <= high; i++) {
        DP[i] = ((i >= zero ? DP[i - zero] : 0)
            + (i >= one ? DP[i - one] : 0)) % MOD;
        if (i >= low && i <= high) {
            ans = (ans + DP[i]) % MOD;
        }
    }
    return ans;
};
