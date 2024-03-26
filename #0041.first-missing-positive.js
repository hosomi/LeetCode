/**
 * @param {number[]} nums
 * @return {number}
 */
var firstMissingPositive = function(nums) {
    const s = new Set(nums)
    for (let i = 1; i < 1000000; i++) {
        if (!s.has(i)) {
            return i;
        }
    }
};
