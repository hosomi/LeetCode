/**
 * @param {number[]} jobDifficulty
 * @param {number} d
 * @return {number}
 */
var minDifficulty = function(jobDifficulty, d) {
    let n = jobDifficulty.length;
    let dp = [];
    for (let i = 0; i < n; i++) {
        dp[i] = [];
        for (let j = 1; j <= d; j++) {
            dp[i][j] = [];
        }
    }

    let diff = recur();
    if (diff === Infinity) {
        return - 1;
    }
    return diff;

    function recur(i = 0, day = 1, max = -Infinity) {
        if (i >= n) {
            return Infinity;
        }

        if (i === n - 1 && day === d) {
            return Math.max(max, jobDifficulty[i]);
        }

        if (day > d) {
            return Infinity;
        }

        if (dp[i][day][max] !== undefined) {
            return dp[i][day][max];
        }

        let currentMax = Math.max(max, jobDifficulty[i]);
        let res1 = recur(i + 1, day, currentMax);
        let res2 = currentMax + recur(i + 1, day + 1, -Infinity);
        let res = Math.min(res1, res2);
        return dp[i][day][max] = res;
    }
};
