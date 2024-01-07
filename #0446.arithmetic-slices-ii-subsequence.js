/**
 * @param {number[]} nums
 * @return {number}
 */
var numberOfArithmeticSlices = function(nums) {
    const length = nums.length;
    let dp = new Array(length); 
    let result = 0;
    for (let i = 0; i < length; i++) {
        dp[i] = new Map();
        for (let j = 0; j < i; j++) {
            const diff = nums[i] - nums[j];
            const count = dp[j].get(diff) || 0;
            dp[i].set(diff, (dp[i].get(diff) || 0) + count + 1);
            result += count;
        }
    }
    return result;
};
