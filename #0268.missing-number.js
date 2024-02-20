/**
 * @param {number[]} nums
 * @return {number}
 */
var missingNumber = function(nums) {
    const results = new Array(nums.length+1).fill(-1);
    for (const num of nums) {
        results[num] = num;
    }
    return results.indexOf(-1);
};
