/**
 * @param {number[]} nums
 * @param {number} minK
 * @param {number} maxK
 * @return {number}
 */
var countSubarrays = function(nums, minK, maxK) {
    let result = 0;
    let min = -1;
    let max = -1;
    let index = -1;
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] < minK || nums[i] > maxK) {
            index = i;
        }

        if (nums[i] == minK) {
            min = i;
        }

        if (nums[i] == maxK) {
            max = i;
        }
        result += Math.max(0, Math.min(min, max) - index);
    }
    return result;
};
