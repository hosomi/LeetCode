/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number}
 */
var maxSumAfterPartitioning = function(arr, k) {
    const length = arr.length;
    let dp = new Array(length + 1).fill(0);
    for (let i = length - 1; i >= 0; i--) {
        let maxSum = -Infinity;
        let len = 0;
        let max = -Infinity;
        for (let j = i; j < Math.min(length, i + k); j++) {
            len++;
            max = Math.max(max, arr[j]);
            maxSum = Math.max(maxSum, ((len * max) + dp[j + 1]));
        }
        dp[i] = maxSum;
    }
    return dp[0];
};
