/**
 * @param {number[]} days
 * @param {number[]} costs
 * @return {number}
 */
var mincostTickets = function(days, costs) {
    const n = days.length;
    const dp = new Array(n).fill(0);
    dp[0] = Math.min(...costs);
    for (let i = 1; i < n; i++) {
        const oneday = dp[i-1] + costs[0];
        let sevendays = costs[1];
        let thirtydays = costs[2];
        let j = i - 1;
        while ((j >= 0) && (days[i] - days[j] < 7)) {
            j--;
        }

        if (j >= 0) {
            sevendays = dp[j] + costs[1];
        }
        j = i - 1;
        
        while ((j >= 0) && (days[i] - days[j] < 30)) {
            j--;
        }

        if (j >= 0) {
            thirtydays = dp[j] + costs[2];
        }
        dp[i] = Math.min(oneday, sevendays, thirtydays);
    }
    return dp[n - 1];
};
