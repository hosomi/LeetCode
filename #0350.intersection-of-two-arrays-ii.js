/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersect = function(nums1, nums2) {
    const counts = {};
    const results = [];
    nums1.forEach(num1 => counts[num1] = ++counts[num1] || 1);
    for (let num2 of nums2) {
        if (counts[num2]) {
            results.push(num2);
            counts[num2]--;
        }
    }
    return results;
};
