/**
 * @param {number[]} nums
 * @param {number} x
 * @return {number}
 */
var minOperations = function(nums, x) {
    let length = nums.length;
    let index = 0;
    let complement_length = -1;
    let complement_sum = 0;
    let total = nums.reduce((left, right) => left + right, 0);
    for (let right = 0; right < length; right++ ) {
        complement_sum += nums[right];
        while (index <= right && complement_sum > total-x) {
            complement_sum -= nums[index++];
        }

        if (complement_sum == total - x) {
            complement_length = Math.max(complement_length,
                right - index + 1);
        }
    }
    return complement_length == -1 ? -1 :
        length - complement_length;
};
