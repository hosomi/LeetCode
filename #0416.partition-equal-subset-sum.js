/**
 * @param {number[]} nums
 * @return {boolean}
 */
var canPartition = function(nums) {

    const total = nums.reduce((a, b) => a + b, 0);
    if (total % 2) {
        return false;
    }

    const target = total / 2;
    let everySum = new Set([0]);
    for (let i = nums.length - 1; i >= 0; i--) {
        const nextSums = new Set()
        for (const sum of everySum) {
            if (nums[i] + sum == target) {
                return true;
            }
            nextSums.add(sum);
            nextSums.add(sum + nums[i]);
        }
        everySum = nextSums;
    }
    
    return everySum.has(target);
};
