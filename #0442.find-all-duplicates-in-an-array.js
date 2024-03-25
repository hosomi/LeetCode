/**
 * @param {number[]} nums
 * @return {number[]}
 */
var findDuplicates = function(nums) {
    const result = []; nums.unshift(0);
    for (let i = 0; i < nums.length; i++) {
        const index = Math.abs(nums[i]);
        if (nums[index] < 0) {
            result.push(index);
        }
        nums[index] *= -1;
    }
    return result;  
};
