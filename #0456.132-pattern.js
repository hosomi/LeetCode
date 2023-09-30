/**
 * @param {number[]} nums
 * @return {boolean}
 */
var find132pattern = function(nums) {
    let min = Number.MAX_SAFE_INTEGER;
    let length = nums.length;
    for (let i = 0; i < length; i++) {
        min = Math.min(min, nums[i]);
        if (min == nums[i]) {
            continue;
        }
        
        for (let k = length - 1; k > i; k--) {
            if (min < nums[k] && nums[k] < nums[i]) {
                return 1;
            }
        }
    }
    return 0;
};
