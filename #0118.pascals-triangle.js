/**
 * @param {number} numRows
 * @return {number[][]}
 */
var generate = function(numRows) {
    let results = [[1]];
    for (let i = 1; i < numRows; i++) {
        let arr = [1];
        for (let j = 1; j < i; j++) {
            arr.push(results[i - 1][j]
                + results[i - 1][j - 1]);
        }
        arr.push(1);
        results.push(arr);
    }
    return results;
};
