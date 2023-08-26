/**
 * @param {number[][]} pairs
 * @return {number}
 */
var findLongestChain = function(pairs) {
    let sorted = pairs.sort((left, right) => left[1] - right[1]);
    return sorted.reduce((acc, [left, right], i) => {
        if (acc.cur < left) {
            acc.length++;
            acc.cur = right;
        }
        return acc;
    }, { cur: -Infinity, length: 0 }).length;
};
