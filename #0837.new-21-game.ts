function new21Game(n: number, k: number, maxPts: number): number {
    if (k == 0 || n >= k + maxPts) {
        return 1.0;
    }

    const dp = [];
    dp[0] = 1.0;
    let sum = 1.0
    let res = 0.0;
    for (let i = 1; i <= n; i++) {
        dp[i] = sum / maxPts;
        if (i < k) {
            sum += dp[i];
        } else {
            res += dp[i];
        }
        if (i >= maxPts) {
            sum -= dp[i - maxPts];
        }
    }
    return res;
};
