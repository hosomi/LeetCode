/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var findKthLargest = function(nums, k) {
    let arr = nums.sort((a, b) => (a - b));
    return arr[arr.length - k];
};
