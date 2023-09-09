/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var combinationSum4 = function(nums, target) {
    let result = new Array(target + 1).fill(0);
    result[0] = 1;
    for (let i = 1; i < target + 1; i++) {
        for (let j = 0; j < nums.length; j++) {
            if (nums[j] <= i) {
                result[i] += result[i - nums[j]];
            }
        }
    }
    return result[target];
};
