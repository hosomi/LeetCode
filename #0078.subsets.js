/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var subsets = function(nums) {
    const sets = [[]];
    for (const num of nums) {
        sets.push(...sets.map((set) => [...set, num]));
    }
    return sets;
};
