/**
 * @param {number[]} nums
 * @return {boolean}
 */
var isMonotonic = function(nums) {
    let isUp = false;
    let isDown = false;
    for (let i = 0; i < nums.length; i++) {
        if (nums[i + 1] > nums[i]) {
            isUp = true;
        }

        if (nums[i + 1] < nums[i]) {
            isDown = true;
        }

        if (isUp && isDown) {
            break;
        }
    }

    return !(isUp && isDown);
};
