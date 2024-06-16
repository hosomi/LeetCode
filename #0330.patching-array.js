/**
 * @param {number[]} nums
 * @param {number} n
 * @return {number}
 */
var minPatches = function(nums, n) {
    let result = 0;
    let i = 0;
    let sum = 0;
    while (sum < n) {
        if (i < nums.length && nums[i] <= sum + 1) {
            sum += nums[i];
            i++;
        } else {
            sum += sum + 1;
            result++;
        }
    }
    return result;
};
