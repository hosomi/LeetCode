/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var subarraysDivByK = function(nums, k) {
    let total = 0;
    let count = 0;
    const seen = new Map([[0, 1]]);
    for (const num of nums) {
        total = ((total + num) % k + k) % k;
        const subCount = seen.get(total) ?? 0;
        count += subCount;
        seen.set(total, subCount + 1);
    }
    return count;
};
