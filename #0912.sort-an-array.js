/**
 * @param {number[]} nums
 * @return {number[]}
 */
var sortArray = function(nums) {
    return nums.sort((left, right) => left - right);
};
