/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function(nums) {
    nums.sort((left, right) => left - right);
    return nums[Math.floor(nums.length / 2)];
};
