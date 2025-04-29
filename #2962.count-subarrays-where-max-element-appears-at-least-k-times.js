/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var countSubarrays = function(nums, k) {
    const max = Math.max(...nums);
    const freq = [];
    return nums.reduce((ans, num, i) => {
        if (num === max) {
            freq.push(i);
        }
        return ans + (freq.length >= k && freq[freq.length - k] + 1);
    }, 0);
};
