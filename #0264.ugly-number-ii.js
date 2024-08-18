/**
 * @param {number} n
 * @return {number}
 */
var nthUglyNumber = function(n) {
    var dp = new Array(n);
    dp[0] = 1;
    let p1 = 0;
    let p2 = 0;
    let p3 = 0;
    for (let i = 1; i < n; i++) {
        let next1 = dp[p1] * 2;
        let next2 = dp[p2] * 3;
        let next3 = dp[p3] * 5;
        dp[i] = Math.min(next1, next2, next3);
        if (dp[i] == next1) {
            p1++;
        }
        if (dp[i] == next2) {
            p2++;
        }
        if (dp[i] == next3) {
            p3++;
        }
    }
    return dp[n - 1];
};
