/**
 * @param {number[]} nums
 * @return {number}
 */
var findDuplicate = function(nums) {
    let result = 0;
    nums.sort();
    for (let j = 1; j < nums.length; j++) {
        nums[j] === nums[j-1] ?
            result = nums[j] : result = result;
    }
    return result;
};
