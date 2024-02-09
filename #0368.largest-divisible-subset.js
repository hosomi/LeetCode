/**
 * @param {number[]} nums
 * @return {number[]}
 */
var largestDivisibleSubset = function(nums) {
    let arr = Array(nums.length).fill([]);
    let results = [];
    nums.sort((left, right)=> left - right);
    for (let i = nums.length - 1; i >= 0; i--) {
        let curr = [];
        for (let j = i + 1; j < nums.length; j++) {
            if ((!(nums[j] % nums[i]) || !(nums[i] % nums[j]))
                && arr[j].length >= curr.length) {
                curr = [...arr[j]];
            }
        }
        arr[i] = [nums[i], ...curr];
        if (results.length < arr[i].length) {
            results = arr[i];
        }
    }
    return results;
};
