/**
 * @param {number[]} nums
 * @param {number} target
 * @return {boolean}
 */
var search = function(nums, target) {
    let left = 0;
    let right = nums.length - 1;
    while (left <= right) {
        if (nums[left] === target) {
            return true;
        }
        
        if (nums[right] === target) {
            return true;
        }

        left++;
        right--;
    }
    return false;
};
