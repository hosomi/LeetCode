/**
 * @param {number[]} nums
 * @return {number[]}
 */
var singleNumber = function(nums) {
    let set = new Set();
    nums.forEach((n) => {
        if (set.has(n)) {
            set.delete(n);
        } else {
            set.add(n);
        }
    });

    return Array.from(set);
};
