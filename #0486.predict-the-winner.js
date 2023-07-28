/**
 * @param {number[]} nums
 * @return {boolean}
 */
var PredictTheWinner = function(nums) {
    let length = nums.length;
    let dp = [];
    for (let i = 0; i < length; i++) {
        dp[i] = new Array(length).fill(0);
        dp[i][i] = nums[i];
    }
    
    for (let i = 2; i <= length; i++) {
        for (let start = 0; start < length - i + 1; start++) {
            const end = start + i - 1;
            dp[start][end] = Math.max(nums[start] - dp[start + 1][end],
                nums[end] - dp[start][end - 1]);
        }
    }
    
    return dp[0][length - 1] >= 0;
};
