/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var searchRange = function(nums, target) {
    let results = [];
    results.push(nums.indexOf(target));
    results.push(nums.lastIndexOf(target));
    return results;
};
