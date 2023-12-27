/**
 * @param {string} colors
 * @param {number[]} neededTime
 * @return {number}
 */
var minCost = function(colors, neededTime) {
    const length = neededTime.length
    if (length < 2) {
        return 0;
    }

    let [count, max, val] = [0, neededTime[0]];
    for (let i = 0; i < length - 1; i++) {
        if (colors[i] !== colors[i + 1]) {
             max = neededTime[i + 1];
             continue;
        }

        val = neededTime[i + 1];
        if (max > val) {
            count += val;
        } else {
            count += max;
            max = val;
        }
    }
    return count;
};
