/**
 * @param {number[]} nums
 * @return {number}
 */
var reductionOperations = function(nums) {
    let result = 0;
    let num = nums.sort((left, right) => right - left)[0];
    for (let i = 0; i < nums.length; i++) {
        if (num != nums[i]) {
            result += i;
            num = nums[i];
        }
    }
    return result;
};
