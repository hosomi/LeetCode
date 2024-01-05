/**
 * @param {number[]} nums
 * @return {number}
 */
var lengthOfLIS = function(nums) {
    let piles = [];
    for (let num of nums) {
        let i = piles.findIndex(pile => pile[0] >= num);
        if (i === -1) {
            piles.push([num]);
        } else {
            piles[i].unshift(num);
        }
    }
    return piles.length;
};
