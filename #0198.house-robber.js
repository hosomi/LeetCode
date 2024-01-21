/**
 * @param {number[]} nums
 * @return {number}
 */
var rob = function(nums) {
    return nums.reduce((acc, nextHouse) => [
        acc[1],
        Math.max(acc[0] + nextHouse,acc[1])],
        [0,0]
    )[1];
};
