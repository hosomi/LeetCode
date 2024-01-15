/**
 * @param {number[][]} matches
 * @return {number[][]}
 */
var findWinners = function(matches) {

    let arr = {};
    for (let i = 0; i < matches.length; i++) {
        arr[matches[i][0]] =
            arr[matches[i][0]] ? arr[matches[i][0]] : 0;
        arr[matches[i][1]] =
            arr[matches[i][1]] ? arr[matches[i][1]] + 1 : 1;
    }

    let left = [];
    let right = [];
    for (const [key, value] of Object.entries(arr)) {
        if (value === 1) {
            right.push(key);
        }
        if (value === 0) {
            left.push(key);
        }
    }
    return [left, right];
};
