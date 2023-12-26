/**
 * @param {number} n
 * @param {number} k
 * @param {number} target
 * @return {number}
 */
var numRollsToTarget = function(n, k, target) {
    const mod = 10**9 + 7;
    const dp = [...Array(target+1)].map(
      () => Array(n + 1).fill(0)
    );
    dp[0][0] = 1;
    
    for (let i = 1; i <= target; i++) {
        for (let j = 1; j <= n; j++) {
            for (let l = 1; l <= k; l++) {
                if (l > i) {
                    break;
                }
                dp[i][j] += dp[i - l][j - 1] % mod;                
            }
        }
    }
    return dp[target][n] % mod;
};
