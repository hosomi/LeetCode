/**
 * @param {number[]} cost
 * @return {number}
 */
var minCostClimbingStairs = function(cost) {
    let arr = cost.slice(0, 2);
    for (let i = 2; i < cost.length; i++) {
        [arr[0], arr[1]] = [arr[1], arr[0]];
        arr[1] = Math.min(arr[0], arr[1]) + cost[i];
    }
    return arr[0] > arr[1] ? arr[1] : arr[0];
};
