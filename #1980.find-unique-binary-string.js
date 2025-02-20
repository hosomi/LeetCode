/**
 * @param {string[]} nums
 * @return {string}
 */
var findDifferentBinaryString = function(nums) {
    return nums.map((row, i) => row[i] === '0' ? '1' : '0').join('');
};
