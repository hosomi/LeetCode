/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var findTargetSumWays = function(nums, target) {
    let count = 0;
    const dp = (i, sum) => {
        if (i == nums.length) {
            if (sum == target) {
                count++;
            }
            return;
        }

        dp(i + 1, sum + nums[i]);
        dp(i + 1, sum - nums[i]);
    };
    dp(0, 0);

    return count;
};
