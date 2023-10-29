/**
 * @param {number} buckets
 * @param {number} minutesToDie
 * @param {number} minutesToTest
 * @return {number}
 */
var poorPigs = function(buckets, minutesToDie, minutesToTest) {
    let max = minutesToTest / minutesToDie + 1;
    let result = 0;
    while (Math.pow(max, result) < buckets) {
        ++result;
    }
    return result;
};
