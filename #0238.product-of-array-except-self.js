/**
 * @param {number[]} nums
 * @return {number[]}
 */
var productExceptSelf = function(nums) {
    const length = nums.length;
    const result = [];
    for (let i = 0; i < length; i++) {
        result[i] = (result[i - 1] ?? 1) * (nums[i - 1] ?? 1);
    }

    let rightProduct = 1;
    for (let i = length - 1; i >= 0; i--) {
        result[i] *= rightProduct;
        rightProduct *= nums[i];
    }

    return result;
};
