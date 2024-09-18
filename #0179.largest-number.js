/**
 * @param {number[]} nums
 * @return {string}
 */
var largestNumber = function(nums) {
    nums = nums.map(String);
    let result = nums.sort((a, b) =>(b + a) - (a + b)).join('');
    return result[0] === '0' ? '0' : result;
};
